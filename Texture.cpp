//
//  Texture.cpp
//  texsyn
//
//  Created by Craig Reynolds on 12/15/19.
//  Copyright © 2019 Craig Reynolds. All rights reserved.
//

#include "Texture.h"
#include <thread>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#pragma clang diagnostic pop

// Rasterize this texture into size² OpenCV image, display in pop-up window.
void Texture::displayInWindow(int size, bool wait) const
{
    rasterizeToImageCache(size, true);
    windowPlacementTool(*raster_);
    if (wait) waitKey();  // Wait for a keystroke in the window.
}

// Display cv::Mat in pop-up window. Stack diagonally from upper left.
void Texture::windowPlacementTool(cv::Mat& mat)
{
    static int window_counter = 0;
    static int window_position = 0;
    std::string window_name = "TexSyn" + std::to_string(window_counter++);
    cv::namedWindow(window_name);       // Create a window for display.
    int tm = 23;  // TODO approximate top margin height
    int window_position_y = window_position + tm + mat.rows;
    cv::moveWindow(window_name, window_position, window_position_y);
    window_position += tm;
    cv::imshow(window_name, mat);  // Show our image inside it.
}

// Rasterize this texture into a size² OpenCV image. Arg "disk" true means
// draw a round image, otherwise a square. Run parallel threads for speed.
void Texture::rasterizeToImageCache(int size, bool disk) const
{
    Timer t("rasterizeToImageCache");
    // If size changed, including from initial value of 0x0, generate raster.
    // (TODO also ought to re-cache if "disk" changes. Issue ignored for now.)
    if ((size != raster_->rows) || (size != raster_->cols))
    {
        // Reset our OpenCV Mat to be (size, size) with 3 floats per pixel.
        raster_->create(size, size, CV_32FC3);
        // TODO Code assumes disk center at window center, so size must be odd.
        assert(((!disk) || (size % 2 == 1)) && "For disk, size must be odd.");
        // Synchronizes access to opencv_image by multiple row threads.
        std::mutex ocv_image_mutex;
        // Collection of all row threads.
        std::vector<std::thread> all_threads;
        // Loop all image rows, bottom to top. For each, launch a thread running
        // rasterizeRowOfDisk() to compute pixels, write to image via mutex.
        for (int j = -(size / 2); j <= (size / 2); j++)
        {
            // This requires some unpacking. It creates a thread which is pushed
            // (using && move semantics, I think) onto the back of std::vector
            // all_row_threads. Because the initial/toplevel thread function is
            // member function of this instance, it is specified as two values,
            // a function pointer AND an instance pointer. The other four values
            // are args to rasterizeRowOfDisk(row, size, disk, image, mutex).
            all_threads.push_back(std::thread(&Texture::rasterizeRowOfDisk, this,
                                              j, size, disk,
                                              std::ref(*raster_),
                                              std::ref(ocv_image_mutex)));
        }
        // Wait for all row threads to finish.
        for (auto& t : all_threads) t.join();
    }
}

// Rasterize the j-th row of this texture into a size² OpenCV image. Expects
// to run in its own thread, uses mutex to synchonize access to the image.
void Texture::rasterizeRowOfDisk(int j, int size, bool disk,
                                 cv::Mat& opencv_image,
                                 std::mutex& ocv_image_mutex) const
{
    // Half the rendering's size corresponds to the disk's center.
    int half = size / 2;
    // First and last pixels on j-th row of time
    int x_limit = disk ? std::sqrt(sq(half) - sq(j)) : half;
    cv::Mat row_image(1, size, CV_32FC3, cv::Scalar(0.5, 0.5, 0.5));
    for (int i = -x_limit; i <= x_limit; i++)
    {
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//        // Read TexSyn Color from Texture at (i, j).
//        Color color = reGamma(getColorClipped(Vec2(i, j) / half));

//            // Read TexSyn Color from Texture at (i, j).
//            Color color(0, 0, 0);
//    //        if (temp_aa_flag)
//            if (temp_aa_subsamples > 1)
//            {
//                Vec2 pixel_center = Vec2(i, j) / half;
//    //            float pixel_radius = 1.0 / size;
//                float pixel_radius = 2.0 / size;
//    //            int subsamples = 16;
//    //            int subsamples = 100;
//    //            for (int k = 0; k < subsamples; k++)
//                for (int k = 0; k < temp_aa_subsamples; k++)
//                {
//                    // TODO note these should use RandomSequence utilities.
//                    Vec2 offset(frandom2(-pixel_radius, pixel_radius),
//                                frandom2(-pixel_radius, pixel_radius));
//                    color += getColorClipped(pixel_center + offset);
//                }
//    //            color = reGamma(color / subsamples);
//                color = reGamma(color / temp_aa_subsamples);
//            }
//            else
//            {
//                color = reGamma(getColorClipped(Vec2(i, j) / half));
//            }

        // Read TexSyn Color from Texture at (i, j).
        Color color(0, 0, 0);
        if (sqrt_of_aa_subsample_count > 1)
        {
            Vec2 pixel_center = Vec2(i, j) / half;
            float pixel_radius = 2.0 / size;

            std::vector<Vec2> offsets;
            RandomSequence rs(pixel_center.hash());

            jittered_grid_NxN_in_square(sqrt_of_aa_subsample_count,
                                        pixel_radius * 2,
                                        rs,
                                        offsets);
            
//            for (int k = 0; k < temp_aa_subsamples; k++)
//            {
//                // TODO note these should use RandomSequence utilities.
//                Vec2 offset(frandom2(-pixel_radius, pixel_radius),
//                            frandom2(-pixel_radius, pixel_radius));
//                color += getColorClipped(pixel_center + offset);
//            }
            
            for (Vec2 offset : offsets)
            {
                color += getColorClipped(pixel_center + offset);
            }
            
//            color = reGamma(color / temp_aa_subsamples);
            color = reGamma(color / sq(sqrt_of_aa_subsample_count));

        }
        else
        {
            color = reGamma(getColorClipped(Vec2(i, j) / half));
        }

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Make OpenCV color, with reversed component order.
        cv::Vec3f opencv_color(color.b(), color.g(), color.r());
        // Write OpenCV color to corresponding pixel on row image:
        row_image.at<cv::Vec3f>(cv::Point(half + i, 0)) = opencv_color;
    }
    // Define a new image which is a "pointer" to j-th row of opencv_image.
    cv::Mat row_in_full_image(opencv_image, cv::Rect(0, half - j, size, 1));
    // Wait to grab lock for access to image. (Lock released at end of block)
    const std::lock_guard<std::mutex> lock(ocv_image_mutex);
    // Copy line_image into the j-th row of opencv_image.
    row_image.copyTo(row_in_full_image);
}

// Display a collection of Textures, each in a window, then wait for a char.
void Texture::displayInWindow(std::vector<const Texture*> textures,
                              int size,
                              bool wait)
{
    for (auto& t : textures) t->displayInWindow(size, false);
    // Wait for keystroke, close windows, exit function.
    if (wait) waitKey();
}

// Writes Texture to a file using cv::imwrite(). Generally used with JPEG
// codec, but pathname's extension names the format to be used. Converts to
// "24 bit" image (8 bit unsigned values for each of red, green and blue
// channels) because most codecs do not support 3xfloat format.
void Texture::writeToFile(int size,
                          const std::string& pathname,
                          Color bg_color,
                          int margin,
                          const std::string& file_type) const
{
    // Make OpenCV Mat instance of type CV_8UC3 (3 by unsigned 8 bit primaries).
    cv::Mat opencv_image(size + margin * 2,
                         size + margin * 2,
                         CV_8UC3,
                         cv::Scalar(255 * bg_color.b(),
                                    255 * bg_color.g(),
                                    255 * bg_color.r()));
    // Ensure cached rendering of Texture is available. (TODO "disk" arg inline)
    rasterizeToImageCache(size, true);
    // Define a new image, a "pointer" to portion of opencv_image inside margin.
    cv::Mat render_target(opencv_image, cv::Rect(margin, margin, size, size));
    // Convert 3xfloat rendered raster to 3x8bit window inside opencv_image
    raster_->convertTo(render_target, CV_8UC3, 255);
    bool ok = cv::imwrite(pathname + file_type, opencv_image);
    std::cout << (ok ? "OK " : "bad") << " write Texture: size=" << size;
    std::cout << ", margin=" << margin << ", bg_color=" << bg_color;
    std::cout << ", path=\"" << pathname + file_type << "\", " << std::endl;
}

// Combines display on screen and writing file, but primary benefit is that
// this allows writing an arbitrarily nested expression of TexSyn
// constructors, whose lifetime extends across both operations.
void Texture::displayAndFile(const Texture& texture,
                             std::string pathname,
                             int size)
{
    texture.displayInWindow(size, false);
    if (pathname != "") texture.writeToFile(size, pathname);
}

void Texture::waitKey()
{
    cv::waitKey(0);
}

// Reset statistics for debugging.
void Texture::resetStatistics() const
{
    // Clear bounds of sampled positions.
    min_x = std::numeric_limits<float>::infinity();
    max_x = -std::numeric_limits<float>::infinity();
    min_y = std::numeric_limits<float>::infinity();
    max_y = -std::numeric_limits<float>::infinity();
}

// Collect statistics for debugging.
void Texture::collectStatistics(Vec2 position, Color color) const
{
    // TODO "color" currently ignored
    // Update bounds of sampled positions.
    if (min_x > position.x()) min_x = position.x();
    if (max_x < position.x()) max_x = position.x();
    if (min_y > position.y()) min_y = position.y();
    if (max_y < position.y()) max_y = position.y();
}

float Texture::min_x = std::numeric_limits<float>::infinity();
float Texture::max_x = -std::numeric_limits<float>::infinity();
float Texture::min_y = std::numeric_limits<float>::infinity();
float Texture::max_y = -std::numeric_limits<float>::infinity();

// Utilities for rasterizing a Texture to tiling of pixels, with versions
// for a square and a disk of pixels. Each require a "size" (width of the
// square or diameter of the disk) and a function to be applied at each
// pixel. The function's parameters are i/j (column/row) indexes of the
// pixel raster, and the corresponding Vec2 in Texture space. [DEPRECATED]
void Texture::rasterizeSquare(int size, PixelFunction pixel_function)
{
    int half = size / 2;
    for (int i = -half; i <= half; i++)
    {
        for (int j = -half; j <= half; j++)
        {
            pixel_function(i, j, Vec2(i / float(half), j / float(half)));
        }
    }
}
void Texture::rasterizeDisk(int size, PixelFunction pixel_function)
{
    int half = size / 2;
    for (int i = -half; i <= half; i++)
    {
        for (int j = -half; j <= half; j++)
        {
            float radius = std::sqrt(sq(i) + sq(j));
            if (radius <= half)
            {
                pixel_function(i, j, Vec2(i / float(half), j / float(half)));
            }
        }
    }
}

// Allocate a generic, empty, cv::Mat. Optionally used for rasterization.
std::shared_ptr<cv::Mat> Texture::emptyCvMat() const
{
    return std::make_shared<cv::Mat>();
}

// Special utility for Texture::diff() maybe refactor to be more general?
void Texture::displayAndFile3(const Texture& t1,
                              const Texture& t2,
                              const Texture& t3,
                              std::string pathname,
                              int size)
{
    // Make OpenCV Mat instance of type CV_8UC3 which is size*3 x size pixels.
    cv::Mat mat(size, size * 3, CV_8UC3);
    // Function to handle each Texture.
    auto subwindow = [&](const Texture& t, int x)
    {
        // Render Texture to its raster_ cv::Mat.
        t.rasterizeToImageCache(size, true);
        // Define a size*size portion of "mat" whose left edge is at "x".
        cv::Mat submat = cv::Mat(mat, cv::Rect(x, 0, size, size));
        // Copy into submat while conveting from rgb float to rgb uint8_t
        t.raster_->convertTo(submat, CV_8UC3, 255);
    };
    subwindow(t1, 0);
    subwindow(t2, size);
    subwindow(t3, size * 2);
    // Write "mat" to file if non-empty "pathname" given.
    std::string file_type = ".png";  // Maybe should be an optional parameter?
    if (pathname != "") cv::imwrite(pathname + file_type, mat);
    // Display "mat" in the TexSyn fashion.
    windowPlacementTool(mat);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//bool Texture::temp_aa_flag = false;
//int Texture::temp_aa_subsamples = 1;

// Each rendered pixel uses an NxN jittered grid of subsamples, where N is:
int Texture::sqrt_of_aa_subsample_count = 1;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
