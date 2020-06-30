//
//  UnitTests.cpp
//  texsyn
//
//  Created by Craig Reynolds on 12/16/19.
//  Copyright © 2019 Craig Reynolds. All rights reserved.
//

// The various "unit test" functions below assert that some supposed property
// (usually an equality, or a "within epsilon" test) exists, and returns true
// if so. Some also print logging.
//
// The main entry point is UnitTests::allTestsOK()

#include "Color.h"
#include "Operators.h"
#include "UnitTests.h"
#include "Utilities.h"
#include "Vec2.h"

// Tests Utilities.h.
bool utilities()
{
    float e = 0.0000001;
    return (withinEpsilon(1.1, 1.2, 0.2) &&
            withinEpsilon(-1.1, -1.2, 0.2) &&
            !withinEpsilon(1.1, 1.2, 0.01) &&
            (sq(2) == 4) &&
            (interpolate(0.1, 0, 10) == 1) &&
            (interpolate(0.1, 0, -10) == -1) &&
            (clip(2, 1, 3) == 2) &&
            (clip(0, 1, 2) == 1) &&
            (clip(3, 1, 2) == 2) &&
            (clip(0, 1, 1) == 1) &&
            (clip(3, 1, 1) == 1) &&
            (sinusoid(0) == 0) &&
            (sinusoid(0.25) < 0.25) &&
            (sinusoid(0.5) == 0.5) &&
            (sinusoid(0.75) > 0.75) &&
            (sinusoid(1) == 1) &&
            (remapInterval(1.5, 1, 2, 20, 30) == 25) &&
            (remapInterval(2, 1, 4, 10, 40) == 20) &&
            (remapIntervalClip(5, 1, 4, 10, 40)) == 40 &&
            !std::isnan(remapInterval(1, 1, 1, 2, 3)) &&
            !std::isnan(remapIntervalClip(1, 1, 1, 2, 3)) &&
            withinEpsilon(fmod_floor(1, 1.23), 1, e) &&
            withinEpsilon(fmod_floor(2, 1.23), 0.77, e) &&
            withinEpsilon(fmod_floor(-1, 1.23), 0.23, e) &&
            withinEpsilon(fmod_floor(-2, 1.23), 0.46, e) &&
            withinEpsilon(fmod_floor(1.23, 1.23), 0, e));
};

// Tests for Color class.
bool color_constructors()
{
    return ((Color().r() == 0) &&
            (Color().g() == 0) &&
            (Color().b() == 0) &&
            (Color(1, 2, 3).r() == 1) &&
            (Color(1, 2, 3).g() == 2) &&
            (Color(1, 2, 3).b() == 3));
}

bool color_equality()
{
    return ((Color() == Color()) && (Color(1, 2, 3) == Color(1, 2, 3)));
}

bool color_assignment()
{
    Color ca1 = Color();
    Color ca2 = Color(1, 2, 3);
    return ((ca1 == Color()) &&
            (ca2 == Color(1, 2, 3)) &&
            (ca2 == (ca2 = Color(1, 2, 3))));
}

bool color_basic_operators()
{
    float e = 0.000001;
    Color wec1(0.1, 0.2, 0.3);
    Color wec2(0.1, 0.2, 0.3 + (e / 2));
    return ((withinEpsilon(wec1, wec2, e)) &&
            (withinEpsilon(wec2, wec1, e)));
}

bool color_luminance()
{
    float e = 0.000001;
    return (withinEpsilon(Color(       ).luminance(), 0,      e) &&
            withinEpsilon(Color(1, 1, 1).luminance(), 1,      e) &&
            withinEpsilon(Color(1, 0, 0).luminance(), 0.2126, e) &&
            withinEpsilon(Color(0, 1, 0).luminance(), 0.7152, e) &&
            withinEpsilon(Color(0, 0, 1).luminance(), 0.0722, e));
}

bool color_hsv()
{
    float e = 0.000001;
    auto from_rgb_to_hsv_to_rgb = [&](float r, float g, float b)
    {
        float h1, s1, v1;
        float r1, g1, b1;
        Color::convertRGBtoHSV(r, g, b, h1, s1, v1);
        Color::convertHSVtoRGB(h1, s1, v1, r1, g1, b1);
        return (withinEpsilon(r, r1, e) &&
                withinEpsilon(g, g1, e) &&
                withinEpsilon(b, b1, e));
    };
    Color c0(1.0, 0.5, 0.0);
    Color c1 = Color::makeHSV(c0.getH(), c0.getS(), c0.getV());
    float h0, s0, v0;
    float r0, g0, b0;
    Color::convertHSVtoRGB(0, 0, 0, r0, g0, b0);
    Color::convertRGBtoHSV(r0, g0, b0, h0, s0, v0);
    bool randoms_ok = true;
    for (int i = 0; i < 10000; i++)
    {
        randoms_ok = randoms_ok && from_rgb_to_hsv_to_rgb(frandom01(),
                                                          frandom01(),
                                                          frandom01());
    }
    return (from_rgb_to_hsv_to_rgb(0.0, 0.0, 0.0) &&
            from_rgb_to_hsv_to_rgb(1.0, 1.0, 1.0) &&
            from_rgb_to_hsv_to_rgb(0.5, 0.5, 0.5) &&
            from_rgb_to_hsv_to_rgb(0.1, 0.5, 0.9) &&
            withinEpsilon(c0.r(), c1.r(), e) &&
            withinEpsilon(c0.g(), c1.g(), e) &&
            withinEpsilon(c0.b(), c1.b(), e) &&
            withinEpsilon(h0, 0, e) &&
            withinEpsilon(v0, 0, e) &&
            withinEpsilon(s0, 0, e) &&
            randoms_ok);
}

bool color_clip()
{
    float e = 0.000001;
    bool all_ok = true;
    for (int i = 0; i < 1000; i ++)
    {
        Color a(frandom2(-1, +10), frandom2(-1, +10), frandom2(-1, +10));
        Color b = a.clipToUnitRGB();
        bool in_range = ((b.r() >= 0) && (b.g() >= 0) && (b.b() >= 0) &&
                         (b.r() <= 1) && (b.g() <= 1) && (b.b() <= 1));
        bool skip = ((a.length() == 0) ||
                     (a.r() <= 0) || (a.g() <= 0) || (a.b() <= 0));
        bool direction_ok = withinEpsilon(a.normalize(), b.normalize(), e);
        if (!in_range || !(skip || direction_ok)) all_ok = false;
    }
    return all_ok;
}

bool vec2_constructors()
{
    return ((Vec2().x() == 0) &&
            (Vec2().y() == 0) &&
            (Vec2(1, -2).x() == 1) &&
            (Vec2(1, -2).y() == -2));
}

bool vec2_equality()
{
    return ((Vec2() == Vec2()) &&
            (Vec2(1, -2) == Vec2(1, -2)));
}

bool vec2_assignment()
{
    Vec2 v1 = Vec2();
    Vec2 v2 = Vec2(1, -2);
    return ((v1 == Vec2()) &&
            (v2 == Vec2(1, -2)) &&
            (v2 == (v2 = Vec2(1, -2))));
}

bool vec2_vector_operations()
{
    return ((Vec2(2, 4).dot(Vec2(10, 20)) == 100) &&
            (Vec2(3, 4).length() == 5) &&
            (Vec2(3, 4).normalize() == Vec2(0.6, 0.8)));
}

bool vec2_basic_operators()
{
    return ((-Vec2(1, 2) == Vec2(-1, -2)) &&
            ((Vec2(1, 2) + Vec2(10, 20)) == Vec2(11, 22)) &&
            ((Vec2(10, 20) - Vec2(1, 2)) == Vec2(9, 18)) &&
            ((Vec2(1, 2) * 5) == Vec2(5, 10)) &&
            ((Vec2(5, 10) / 5) == Vec2(1, 2)) &&
            (Vec2(1, 2) < Vec2(-3, -4)));
}

bool vec2_random_point()
{
    bool all_ok = true;
    for (int i = 0; i < 1000; i ++)
        if (Vec2::randomPointInUnitDiameterCircle().length() > 0.5)
            all_ok = false;
    return all_ok;
}

bool vec2_rotate()
{
    bool all_ok = true;
    for (int i = 0; i < 100; i ++)
    {
        float angle = frandom2(-60, +60);  // In radians, to test large angles.
        float cos = std::cos(angle);
        float sin = std::sin(angle);
        Vec2 v = Vec2(1, 0).rotate(angle);
        if ((v.x() != cos) || (v.y() != -sin)) all_ok = false;
    }
    return all_ok;
}

bool gradation_test()
{
    Vec2 point1(0.2, 0.2);
    Vec2 point2(0.8, 0.8);
    Color color1(1, 0, 1);
    Color color2(0, 1, 1);
    Uniform uniform1(color1);
    Uniform uniform2(color2);
    Gradation graduation(point1, uniform1, point2, uniform2);
    Vec2 midpoint = interpolate(0.5, point1, point2);
    Color midcolor = interpolate(0.5, color1, color2);
    float e = 0.00001;
    auto off_axis_sample = [&](float f)
    {
        Vec2 on_axis = interpolate(f, point1, point2);
        Vec2 off_axis = Vec2(-1, 1) * frandom2(-10, 10);
        // TODO maybe instead of predicting what color we expect to find
        // (which requires internal knowledge of the texure) maybe compare
        // two samples, say from plus and minus off_axis.
        Color expected_color = interpolate(sinusoid(f), color1, color2);
        Color sampled_color = graduation.getColor(on_axis + off_axis);
        return withinEpsilon(sampled_color, expected_color, e);
    };
    return ((graduation.getColor(point1) == color1) &&
            (graduation.getColor(point2) == color2) &&
            withinEpsilon(graduation.getColor(midpoint), midcolor, e) &&
            withinEpsilon(graduation.getColor(Vec2(0, 0)), color1, e) &&
            withinEpsilon(graduation.getColor(Vec2(1, 1)), color2, e) &&
            [&](){
                for (int i = 0; i < 10; i++)
                    if (!off_axis_sample(i * 0.1)) return false;
                return true;
            }());
}

bool spot_test()
{
    Vec2 center(-0.4, -0.4);
    float inner_radius = 0.1;
    float outer_radius = 0.3;
    Color inner_color(1, 1, 0);
    Color outer_color(0, 1, 0);
    Uniform uniform_ic(inner_color);
    Uniform uniform_oc(outer_color);
    Spot spot(center, inner_radius, uniform_ic, outer_radius, uniform_oc);
    Color midcolor = interpolate(0.5, inner_color, outer_color);
    float midradius = (inner_radius + outer_radius) / 2;
    Vec2 midpoint = center + (Vec2(1, 0) * midradius);
    float e = 0.000001;
    return ((spot.getColor(center) == inner_color) &&
            (spot.getColor(midpoint * 2) == outer_color) &&
            withinEpsilon(spot.getColor(midpoint), midcolor, e) &&
            [&](){
                for (int i = 0; i < 100; i++) // try 100 times
                {
                    // Two random vectors, with the same random radius in
                    // transition zone, should have the same color.
                    float r_radius = frandom2(inner_radius, outer_radius);
                    Vec2 rv1 = Vec2::randomUnitVector() * r_radius;
                    Vec2 rv2 = Vec2::randomUnitVector() * r_radius;
                    Color color1 = spot.getColor(center + rv1);
                    Color color2 = spot.getColor(center + rv2);
                    if (!withinEpsilon(color1, color2, e)) return false;
                }
                return true;
            }());
}

bool grating_test()
{
    float e = 0.0001;
    return ([&]()
            {
                for (int i = 0; i < 100; i++) // try 100 times
                {
                    // Define a random Grating
                    Vec2 p1 = Vec2::randomPointInUnitDiameterCircle();
                    Vec2 p2 = Vec2::randomPointInUnitDiameterCircle();
                    Color c1 = Color::randomUnitRGB();
                    Color c2 = Color::randomUnitRGB();
                    Uniform u1(c1);
                    Uniform u2(c2);
                    Grating grating(p1, u1, p2, u2, frandom01(), 0.5);
                    // Pick a random point between p1 and p2.
                    Vec2 between = interpolate(frandom01(), p1, p2);
                    // Pick another point along the line p1,p2 which is
                    // some random integer multiple of offset away.
                    Vec2 offset = p2 - p1;
                    Vec2 other = between + (offset * int(frandom2(-5, 5)));
                    // Read back colors from midpoint, between, and other.
                    Color gc_midpoint = grating.getColor((p1 + p2) / 2);
                    Color gc_between = grating.getColor(between);
                    Color gc_other = grating.getColor(other);
                    // Check if everything is as expected
                    bool ok = ((grating.getColor(p1) == c1) &&
                               (grating.getColor(p2) == c1) &&
                               withinEpsilon(gc_midpoint, c2, e) &&
                               withinEpsilon(gc_between, gc_other, e));
                    if (!ok) return false;
                }
                return true;
            }());
}

// TODO "subtest"
#define st(e)                         \
[&]()                                 \
{                                     \
    bool _e_ok = (e);                 \
    if (!_e_ok)                       \
    {                                 \
        std::cout << "fail: " << #e;  \
        std::cout << std::endl;       \
    }                                 \
    return _e_ok;                     \
}()

bool operators_minimal_test()
{
    float e = 0.000001;
    Color black(0, 0, 0);
    Color white(1, 1, 1);
    Color gray(0.5, 0.5, 0.5);
    Uniform bt(black);  // black texture
    Uniform gt(gray);   // gray texture
    Uniform wt(white);  // white texture
    Max mx(bt, wt);
    Min mn(bt, wt);
    Add ad(wt, gt);
    Subtract s1(wt, gt);
    Subtract s2(bt, gt);
    float ri = 0.2;  // spot radius inner
    float ro = 0.8;  // spot radius outer
    Spot sp(Vec2(0, 0), ri, wt, ro, bt);
    SoftMatte sm(sp, bt, wt);
    return ([&]()
            {
                bool all_ok = true;
                for (int i = 0; i < 1000; i++) // try 1000 times
                {
                    Vec2 r_pos = Vec2::randomPointInUnitDiameterCircle() * 2;
                    float r = r_pos.length();
                    float r_remap = remapIntervalClip(r, ri, ro, 0, 1);
                    float spot_profile = sinusoid(r_remap);
                    Color sm_color = interpolate(spot_profile, white, black);
                    bool ok =
                    (st(withinEpsilon(bt.getColor(r_pos), black, e)) &&
                     st(withinEpsilon(wt.getColor(r_pos), white, e)) &&
                     st(withinEpsilon(mx.getColor(r_pos), white, e)) &&
                     st(withinEpsilon(mn.getColor(r_pos), black, e)) &&
                     st(withinEpsilon(ad.getColor(r_pos), white + gray, e)) &&
                     st(withinEpsilon(s1.getColor(r_pos), white - gray, e)) &&
                     st(withinEpsilon(s2.getColor(r_pos), black - gray, e)) &&
                     st(withinEpsilon(sm.getColor(r_pos), sm_color, e)));
                    if (!ok) all_ok = false;
                }
                return all_ok;
            }());
}

bool noise_ranges()
{
    auto test_range = [](std::function<float(Vec2)> noise_function,
                         float min_threshold, float max_threshold)
    {
        std::pair<float, float> min_max =
            PerlinNoise::measure_range(noise_function);
        // std::cout << "noise_ranges: ";
        // std::cout << "min_range = " << min_max.first << ", ";
        // std::cout << "max_range = " << min_max.second << std::endl;
        return ((min_max.first <= min_threshold) &&
                (min_max.second >= max_threshold));
    };
    return (test_range(PerlinNoise::noise2d,     -1, 1) &&
            test_range(PerlinNoise::unitNoise2d,  0, 1) &&
            test_range(PerlinNoise::turbulence2d, 0, 1) &&
            test_range(PerlinNoise::brownian2d,   0, 1) &&
            test_range(PerlinNoise::furbulence2d, 0, 1) &&
            test_range(PerlinNoise::wrapulence2d, 0, 1));
}

// Used only in UnitTests::allTestsOK()
#define logAndTally(e)                       \
{                                            \
    bool _e_ok = e();                        \
    std::cout << "\t";                       \
    std::cout << (_e_ok ? "pass" : "FAIL");  \
    std::cout << " " << #e;                  \
    std::cout << std::endl << std::flush;    \
    if (!_e_ok) all_tests_passed = false;    \
}

bool UnitTests::allTestsOK()
{
    Timer timer("Run time for unit test suite: ", "");
    bool all_tests_passed = true;
    logAndTally(utilities);
    logAndTally(color_constructors);
    logAndTally(color_equality);
    logAndTally(color_assignment);
    logAndTally(color_basic_operators);
    logAndTally(color_luminance);
    logAndTally(color_hsv);
    logAndTally(color_clip);
    logAndTally(vec2_constructors);
    logAndTally(vec2_equality);
    logAndTally(vec2_assignment);
    logAndTally(vec2_vector_operations);
    logAndTally(vec2_basic_operators);
    logAndTally(vec2_random_point);
    logAndTally(vec2_rotate);
    logAndTally(gradation_test);
    logAndTally(spot_test);
    logAndTally(grating_test);
    logAndTally(operators_minimal_test);
    logAndTally(noise_ranges);
    std::cout << std::endl;
    std::cout << (all_tests_passed ? "All tests PASS." : "Some tests FAIL.");
    std::cout << std::endl << std::endl;
    return all_tests_passed;
}

// This utility is intended to verify that all Texture types exist, can be
// constructed, and produce a "reasonable" output. It is currently not used
// anywhere except when it was called "manually" from main() on June 7, 2020
// for testing. Note that no mechanism automatically adds clauses to this
// function when new texture types are defined, so it needs to be updated
// manually, which of course reduces its effectiveness for catching (e.g.)
// accidentally deleted definitions.
void UnitTests::instantiateAllTextureTypes()
{
    Vec2 p1(-0.1, 0);
    Vec2 p2(0.1, 0);
    Vec2 p3(0.4, 0.6);
    Uniform black(Color(0, 0, 0));
    Uniform white(Color(1, 1, 1));
    Uniform red(Color(1, 0, 0));
    Uniform cyan(Color(0, 1, 1));
    Grating white_cyan(Vec2(0, 0.2), white, Vec2(0, 0), cyan, 0.1, 0.5);
    Grating black_red(Vec2(0.1, 0), black, Vec2(0, 0), red, 0.1, 0.5);
    Grating& t1 = white_cyan;
    Grating& t2 = black_red;
    ColorNoise t3(p1, p3, 0.2);
    
    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200607_";
    int counter = 0;
    
    auto do_thumbnail = [&](const Texture& texture)
    {
        std::string s = path + "thumbnail_" + std::to_string(counter++);
        // TODO TEMP
        s = "";
        Texture::displayAndFile(texture, s, 101);
    };

    do_thumbnail(Uniform(0.5));
    do_thumbnail(Spot(p1, 0.1, t1, 0.2, t2));
    do_thumbnail(Gradation(p1, t1, p2, t2));
    do_thumbnail(Grating(p1, t1, p3, t2, 1, 0.5));
    do_thumbnail(SoftMatte(t1, t2, t3));
    do_thumbnail(Add(t1, t2));
    do_thumbnail(Subtract(t1, t2));
    do_thumbnail(Multiply(t1, t2));
    do_thumbnail(Max(t1, t2));
    do_thumbnail(Min(t1, t2));
    do_thumbnail(AbsDiff(t1, t2));
    do_thumbnail(Noise(p1, p2, t1, t2));
    do_thumbnail(Brownian(p1, p2, t1, t2));
    do_thumbnail(Turbulence(p1, p2, t1, t2));
    do_thumbnail(Furbulence(p1, p2, t1, t2));
    do_thumbnail(Wrapulence(p1, p2, t1, t2));
    do_thumbnail(MultiNoise(p1, p2, t1, t2, 0.5));
    do_thumbnail(ColorNoise(p1, p2, 0.5));
    do_thumbnail(BrightnessToHue(0.5, t1));
    do_thumbnail(Wrap(2, p1, p2, t1));
    do_thumbnail(StretchSpot(5, 1, p1, t1));
    do_thumbnail(Stretch(Vec2(2, 3), p2, t1));
    do_thumbnail(SliceGrating(p3, p2, t1));
    do_thumbnail(SliceToRadial(p3, p2, t1));
    do_thumbnail(SliceShear(p3, p2, t1, Vec2(0.4, 0.1), p1, t2));
    do_thumbnail(Colorize(Vec2(1, 0.2), p1, t2, t3));
    do_thumbnail(MobiusTransform(p3, p1, Vec2(0.4, 0.1), p2, t1));
    do_thumbnail(Scale(0.5, t1));
    do_thumbnail(Rotate(0.5, t1));
    do_thumbnail(Translate(p1, t1));
    do_thumbnail(Blur(0.2, t1));
    do_thumbnail(SoftThreshold(0, 1, t1));
    do_thumbnail(EdgeDetect(0.1, t1));
    do_thumbnail(EdgeEnhance(0.1, 1, t1));
    do_thumbnail(AdjustHue(0.25, t1));
    do_thumbnail(AdjustSaturation(0.5, t1));
    do_thumbnail(AdjustBrightness(0.5, t1));
    do_thumbnail(Twist(10, 2, p1, t1));
    do_thumbnail(BrightnessWrap(0.4, 0.6, t3));
    do_thumbnail(Mirror(p3, p2, t1));
    do_thumbnail(Ring(9, p3, p1, t1));
    do_thumbnail(Row(Vec2(0.1, 0.1), p1, t1));
    do_thumbnail(Shader(Vec3(1, 1, 1), 0.2, t1, t3));
    do_thumbnail(LotsOfSpots(0.8, 0.1, 0.4, 0.05, 0.01, t1, t2));
    do_thumbnail(ColoredSpots(0.8, 0.1, 0.4, 0.05, 0.01, t1, t2));
    do_thumbnail(LotsOfButtons(0.8, 0.1, 0.4, 0.05, 0.01, p1, t1, 1, t2));
    do_thumbnail(Gamma(0.5, t3));
    do_thumbnail(RgbBox(0.2, 1, 0, 0.2, 0.2, 1, t1));
}
