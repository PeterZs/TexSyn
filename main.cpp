//
//  main.cpp
//  texsyn
//
//  Created by Craig Reynolds on 12/15/19.
//  Copyright © 2019 Craig Reynolds. All rights reserved.
//

#include "Texture.h"
#include "Generators.h"
#include "Operators.h"
#include "UnitTests.h"
#include "Utilities.h"

bool run_unit_tests = false;

int main(int argc, const char * argv[])
{
    // TODO TEMP run unit tests
    if (run_unit_tests) UnitTests::allTestsOK();
    
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // TODO TEMP testing display utility and generators.
//    Spot spot(Vec2(0, 0), 0.2, Color(1, 1, 1), 0.6, Color(0, 0, 0));
//    spot.displayInWindow();
    
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Grating grating(Vec2(0.1, 0.1), Color(0, 0.8, 0),
//                    Vec2(0.5, 0.3), Color(0.85, 0.85, 0), 0.3);
//    grating.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200101_";
//    grating.writeToFile(511, path + "Grating");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Gradation gradation(Vec2(0.4, -0.2), Color(0.9, 0.0, 0.0),
//                        Vec2(-0.4, 0.2), Color(0.9, 0.9, 0.9));
//    gradation.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200101_";
//    gradation.writeToFile(511, path + "Gradation");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Spot sp(Vec2(0, 0), 0.2, Color(1, 1, 1), 0.8, Color(0, 0, 0));
//    Grating g1(Vec2(-0.2, 0), Color(0, 0, 0),
//               Vec2( 0.2, 0), Color(1, 1, 1), 1);
//    Grating g2(Vec2(0, -0.1), Color(1, 0, 1),
//               Vec2(0,  0.1), Color(0, 0, 1), 0.2);
//    SoftMatte sm(sp, g1, g2);
//    sm.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200101_";
//    sm.writeToFile(511, path + "SoftMatte");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Grating g1(Vec2(-0.2, 0), Color(0, 0, 0),
//               Vec2( 0.2, 0), Color(1, 1, 1), 1);
//    Grating g2(Vec2(0, -0.1), Color(1, 0, 1),
//               Vec2(0,  0.1), Color(0, 0, 1), 0.2);
//    Max mx(g1, g2);
//    Min mn(g1, g2);
//    Texture::displayInWindow({&mx, &mn});
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200101_";
//    mx.writeToFile(511, path + "Max");
//    mn.writeToFile(511, path + "Min");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Noise no(0.10, Vec2(3, 5), Color(0, 0, 1), Color(1, 1, 0));
//    no.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200103_";
//    no.writeToFile(511, path + "Noise");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Brownian br(0.20, Vec2(3, 5), Color(0, 1, 0), Color(0.3, 0.3, 0.3));
//    br.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200104_";
//    br.writeToFile(511, path + "Brownian");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Turbulence tu(0.3, Vec2(2, -5), Color(0.3, 0, 0.3), Color(1, 0.6, 0));
//    tu.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200106_";
//    tu.writeToFile(511, path + "Turbulence");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Furbulence fu(0.25, Vec2(-1, 2), Color(1, .1, .3), Color(.3, .1, 1));
//    fu.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200110_";
//    fu.writeToFile(511, path + "Furbulence");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    SoftMatte(Spot(Vec2(0, 0),
//                   0.1, Color(0, 0, 0),
//                   0.9, Color(1, 1, 1)),
//              Furbulence(0.1, Vec2(1, 2),
//                         Color(1, 1, 1), Color(.7, .7, 0)),
//              Turbulence(0.2, Vec2(-5, 7),
//                         Color(0, 0, 0), Color(.3, .3, 1))).displayInWindow();
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200110_";
//    SoftMatte(Spot(Vec2(0, 0),
//                   0.1, Color(0, 0, 0),
//                   0.9, Color(1, 1, 1)),
//              Furbulence(0.1, Vec2(1, 2),
//                         Color(1, 1, 1), Color(.7, .7, 0)),
//              Turbulence(0.2, Vec2(-5, 7),
//                         Color(0, 0, 0),
//                         Color(.3, .3, 1))).writeToFile(511,
//                                                        path + "comparison");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    Wrapulence wr(0.9, Vec2(-2, -9), Color(0, 0, 0), Color(1, 0.6, 0));
//    wr.displayInWindow();
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200111_";
//    wr.writeToFile(511, path + "Wrapulence");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    // Comparison of 5 noise varieties, test for MultiNoise. (Jan 12, 2020)
//    {
//        float scale = 0.3;
//        Vec2 center(0, 0);
//        Color white(1, 1, 1);
//        Color black(0, 0, 0);
//        Color magenta(1, 0.3, 1);
//        Color red(1, 0.3, 0.3);
//        Color yellow(1, 1, 0.3);
//        Color green(0.3, 1, 0.3);
//        Color cyan(0.3, 1, 1);
//        // Noise noise(scale, center, black, magenta);
//        // Brownian brownian(scale, center, black, red);
//        // Turbulence turbulence(scale, center, black, yellow);
//        // Furbulence furbulence(scale, center, black, green);
//        // Wrapulence wrapulence(scale, center, black, cyan);
//        MultiNoise noise(scale, center, black, magenta, 0.0);
//        MultiNoise brownian(scale, center, black, red, 0.2);
//        MultiNoise turbulence(scale, center, black, yellow, 0.4);
//        MultiNoise furbulence(scale, center, black, green, 0.6);
//        MultiNoise wrapulence(scale, center, black, cyan, 0.8);
//        auto spot = [&](float r) { return Spot(center,r,black,r+0.05,white); };
//        SoftMatte(spot(0.2),
//                  wrapulence,
//                  SoftMatte(spot(0.4),
//                            furbulence,
//                            SoftMatte(spot(0.6),
//                                      turbulence,
//                                      SoftMatte(spot(0.8),
//                                                brownian,
//                                                noise)))).displayInWindow();
//        std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200112_";
//        SoftMatte(spot(0.2),
//                  wrapulence,
//                  SoftMatte(spot(0.4),
//                            furbulence,
//                            SoftMatte(spot(0.6),
//                                      turbulence,
//                                      SoftMatte(spot(0.8),
//                                                brownian,
//                                                noise))))
//            .writeToFile(511, path + "MultiNoise");
//
//    }
    
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    //Grating g1(Vec2(0, 0), Color(0, 0, 0), Vec2(0.05, 0.2), Color(1, 1, 1), 1);
    //Grating g2(Vec2(0, 0), Color(0, 0, 0), Vec2(0.05, -0.2), Color(1, 1, 1), 1);
    //BrightnessToHue(0.1, Multiply(g1, g2)).displayInWindow();

//    // Following graygratings and BrightnessToHue examples from 2009
//    float angle = pi *  0.6;
//    float frequency = 25;
//    Vec2 basis(0, pi / frequency);
//    Vec2 basis1 = basis.rotate(+angle);
//    Vec2 basis2 = basis.rotate(-angle);
//    Color black(0, 0, 0);
//    Color white(1, 1, 1);
//    Color gray25(0.25, 0.25, 0.25);
//    Grating g1(-basis1, black, basis1, gray25, 1);
//    Grating g2(-basis2, black, basis2, gray25, 1);
//    Grating g0(Vec2(), black, Vec2(0, 2), Color(0.5, 0.5, 0.5), 1);
//    Add s0(g1, g2);
//    Add gray_gratings(g0, s0);
//    BrightnessToHue bth(0.5, gray_gratings);
//    Texture::displayInWindow({&g0, &g1, &g2, &s0, &gray_gratings, &bth});
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200113_";
//    gray_gratings.writeToFile(511, path + "gray_gratings");
//    bth.writeToFile(511, path + "BrightnessToHue");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    Grating blue_stripes(Vec2(), Color(), Vec2(0.1, 0.2), Color(0, 0, 1), 0.8);
//    Gradation red_grad(Vec2(), Color(1, 0, 0), Vec2(0, 1), Color());
//    Add both(blue_stripes, red_grad);
//    Wrap wrap(5, Vec2(), Vec2(0, 1), both);
//    Texture::displayInWindow({&blue_stripes, &red_grad, &both, &wrap});
    
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for Wrap with arbitrary center and fixed_ray. Jan 15
//    Grating red_stripes(Vec2(0, 0), Color(1, 0, 0),
//                        Vec2(0.1, 0.1), Color(0.3, 0, 0), 0.3);
//    Grating green_stripes(Vec2(0, 0), Color(0, 1, 0),
//                          Vec2(-0.1, 0.1), Color(0, 0.3, 0), 0.3);
//    Add plaid(red_stripes, green_stripes);
//    // With identity transform.
//    Wrap wrap1(5, Vec2(), Vec2(0, 1), plaid);
//    // In this version, the discontinuity (-y,  opposite "fixed_ray") is along
//    // (-1, -1). Also noticable aliasing near "center".
//    Wrap wrap2(5, Vec2(0.2, 0.2), Vec2(1, 1), plaid);
//    Texture::displayInWindow({
//        &red_stripes,
//        &green_stripes,
//        &plaid,
//        &wrap1,
//        &wrap2});
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200115_";
//    plaid.writeToFile(511, path + "plaid");
//    wrap1.writeToFile(511, path + "Wrap_1");
//    wrap2.writeToFile(511, path + "Wrap_2");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for StretchSpot, Jan 16
//    Grating red_stripes(Vec2(0, 0), Color(1, 0, 0),
//                        Vec2(0.1, 0.1), Color(0.3, 0, 0), 0.3);
//    Grating green_stripes(Vec2(0, 0), Color(0, 1, 0),
//                          Vec2(-0.1, 0.1), Color(0, 0.3, 0), 0.3);
//    Add plaid(red_stripes, green_stripes);
//    float radius = 0.8;
//    float dist = 0.65;
//    StretchSpot ss1(4.0, radius, Vec2(+dist, +dist), plaid);
//    StretchSpot ss2(0.2, radius, Vec2(-dist, +dist), ss1);
//    StretchSpot ss3(0.2, radius, Vec2(-dist, -dist), ss2);
//    StretchSpot ss4(4.0, radius, Vec2(+dist, -dist), ss3);
//    StretchSpot ss5(4.0, radius, Vec2(-dist, -dist), ss2);
//    StretchSpot ss6(0.2, radius, Vec2(+dist, -dist), ss5);
//    Texture::displayInWindow({ &plaid, &ss4, &ss6 });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200116_";
//    ss4.writeToFile(511, path + "StretchSpot_1");
//    ss6.writeToFile(511, path + "StretchSpot_2");
//
//
//    //    // TODO TEMP TEST related to size of inverse LUT
//    //    Grating vert_stripes(Vec2(0, 0), Color(1, 1, 1),
//    //                         Vec2(0.1, 0), Color(0, 0, 0), 0.2);
//    //    StretchSpot(0.5, 10, Vec2(-5, 0), vert_stripes).displayInWindow();
//
//    //    // TODO TEMP TEST for test for memory leaks
//    //    Color c(0, 0, 0);
//    //    int count = 10000;
//    //    for (int i = 0; i < count; i++)
//    //    {
//    //        StretchSpot ss(0.5, 10, Vec2(-5, 0), vert_stripes);
//    //        c = c + ss.getColor(Vec2());
//    //        if (((i + 1) % (count / 100)) == 0) debugPrint(c);
//    //    }
//    //    debugPrint(c);

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    // Demo for ColorNoise, Jan 20
//    ColorNoise cn1(1, Vec2(-7, 4), 0.0);
//    ColorNoise cn2(0.5, Vec2(-18, -20), 0.8);
//    ColorNoise cn3(0.08, Vec2(15, -12), 0.6);
//    Texture::displayInWindow({ &cn1, &cn2, &cn3 });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200120_";
//    cn1.writeToFile(511, path + "ColorNoise_1");
//    cn2.writeToFile(511, path + "ColorNoise_2");
//    cn3.writeToFile(511, path + "ColorNoise_3");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    // Testing Texture::rasterizer() Jan 20, 2020
//    Noise n(0.2, Vec2(), Color(1, 0, 0), Color(1, 1, 0));
//    Grating g(Vec2(), Color(0, 1, 1), Vec2(0.1, 0.1), Color(0, 0, 1), 0.5);
//    Texture::diff(n, g);

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    // Demo for Stretch texture operator, Jan 21, 2020
//
//    ColorNoise cn(0.6, Vec2(5, -2), 0.6);
//    Stretch2009 old1(0.2, pi / 4, Vec2(0, 0), cn);
//    Stretch s1(Vec2(0.2, 0).rotate(pi / 4), Vec2(0, 0), cn);
//    // Texture::diff(old1, s1);
//
//    float r_in = 0.33;
//    float r_out = 0.35;
//    Vec2 p1(0, 0.4);
//    Vec2 p2 = p1.rotate(2 * pi / 3);
//    Vec2 p3 = p2.rotate(2 * pi / 3);
//    Spot spot1(p1, r_in, Color(1, 1, 0), r_out, Color(0, 0, 0));
//    Spot spot2(p2, r_in, Color(0, 1, 1), r_out, Color(0, 0, 0));
//    Spot spot3(p3, r_in, Color(1, 0, 1), r_out, Color(0, 0, 0));
//    Add two_spots(spot1, spot2);
//    Add three_spots(spot3, two_spots);
//    Stretch2009 old2(2, (-2 * pi / 6) + (pi / 2), p2, three_spots);
//    Stretch s2((-p2).normalize() * 2, p2, three_spots);
//    // shows the effect of "center" argument
//    // Stretch test3((-p2).normalize() * 0.5, p2, three_spots);
//    // Texture::diff(s2, test3);
//
//    Texture::displayInWindow({ &cn, &s1, &three_spots, &s2 });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200121_";
//    cn.writeToFile(511, path + "ColorNoise");
//    s1.writeToFile(511, path + "Stretch_1");
//    three_spots.writeToFile(511, path + "three_spots");
//    s2.writeToFile(511, path + "Stretch_2");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for SliceGrating, Jan 23, 2020
//    ColorNoise cn(0.6, Vec2(5, -2), 0.6);
//    SliceGrating sg1(Vec2(1, 2) * 2.0, Vec2(0.5, 0.5), cn);
//    SliceGrating sg2(Vec2(1, 2) * 1.0, Vec2(0.5, 0.5), cn);
//    SliceGrating sg3(Vec2(1, 2) * 0.5, Vec2(0.5, 0.5), cn);
//    SliceGrating sg4(Vec2(2, 1) * 0.5, Vec2(0.5, 0.5), cn);
//    Texture::displayInWindow({ &cn, &sg1, &sg2, &sg3, &sg4 });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200123_";
//    cn.writeToFile(511, path + "color_noise");
//    sg1.writeToFile(511, path + "SliceGrating1");
//    sg2.writeToFile(511, path + "SliceGrating2");
//    sg3.writeToFile(511, path + "SliceGrating3");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for SliceToRadial, Jan 24, 2020
//    ColorNoise cn(0.6, Vec2(5, -2), 0.6);
//    SliceToRadial sr1(Vec2(1, 1), Vec2(0, 0), cn);
//    SliceToRadial sr2(Vec2(1, 1), Vec2(0.5, 0.5), cn);
//    SliceToRadial sr3(Vec2(1, 0), Vec2(0.5, 0.5), cn);
//    SliceToRadial sr4(Vec2(2, 0), Vec2(0.5, 0.5), cn);
//    Texture::displayInWindow({ &cn, &sr1, &sr2, &sr3, &sr4 });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200124_";
//    sr1.writeToFile(511, path + "SliceToRadial1");
//    sr2.writeToFile(511, path + "SliceToRadial2");
//    sr3.writeToFile(511, path + "SliceToRadial3");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // Demo for SliceShear, Jan 25, 2020
    // Note: I returned to this on March 20. I left this unchanged but
    // made a copy at the bottom of the file for further experiments.
//        ColorNoise cn(0.6, Vec2(5, -2), 0.6);
//    //    Grating gr(Vec2(0, 0), Color(1, 0, 1), Vec2(0, 0.1), Color(1, 1, 0), 0.2);
//        Grating gr(Vec2(0, 0), Color(0.9, 0, 0.9),
//                   Vec2(0, 0.3), Color(0.9, 0.9, 0),
//                   0.2);

//    //    SliceShear ss1(Vec2(1, 1), Vec2(), cn, Vec2(0, 1), Vec2(), gr);
//        SliceShear ss1(Vec2(-.7, .7), Vec2(), cn, Vec2(0, 1), Vec2(), gr);
//        SliceShear ss2(Vec2(.1, .1), Vec2(), cn, Vec2(0, 1), Vec2(), gr);
//        SliceShear ss3(Vec2(0.5, 0), Vec2(), cn, Vec2(0, 0.7), Vec2(), gr);
//
//    //    SliceShear ss4(Vec2(1, -1), Vec2(1, 0), cn, Vec2(2, 0), Vec2(2, 1), ss3);
//    //    SliceShear ss4(Vec2(.5, -.5), Vec2(1, 0), cn, Vec2(2, 0), Vec2(2, 1), ss3);
//        SliceShear ss4(Vec2(1, -1), Vec2(1, 0), cn, Vec2(2, 0), Vec2(2, 1), ss3);
//
//    //    Texture::displayInWindow({ &cn, &gr, &ss1, &ss2, &ss3, &ss4 });
    
    
    
//        Spot sp(Vec2(), 0.2, Color(1, 0, 0), 0.5, Color(0, 0, 0));
//    //    Grating sine(Vec2(0, 0), Color(1, 1, 1), Vec2(0, 0.2), Color(0, 0, 0), 1);
//    //    SliceShear sssp1(Vec2(0, 1), Vec2(), sine, Vec2(0, 1), Vec2(), sp);
//        Grating sine(Vec2(0, 0), Color(1, 1, 1), Vec2(0.2, 0), Color(0, 0, 0), 1);
//        SliceShear sssp1(Vec2(1, 0), Vec2(), sine, Vec2(2, 0), Vec2(), sp);
//
//        Texture::displayInWindow({ &sp, &sine, &sssp1 });

    
//    ColorNoise cn(0.6, Vec2(5, -2), 0.6);
//    Grating gr(Vec2(0, 0), Color(0.9, 0, 0.9),
//               Vec2(0, 0.3), Color(0.9, 0.9, 0),
//               0.2);
//    SliceShear zz(Vec2(1, 1), Vec2(), cn, Vec2(0, 1), Vec2(), gr);
//    Texture::displayInWindow({ &cn, &gr, &zz });
    
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for MobiusTransform, Jan 28, 2020
//    Grating red_stripes(Vec2(0, 0), Color(1, 0, 0),
//                        Vec2(0.1, 0.1), Color(0.3, 0, 0), 0.3);
//    Grating green_stripes(Vec2(0, 0), Color(0, 1, 0),
//                          Vec2(-0.1, 0.1), Color(0, 0.3, 0), 0.3);
//    Add plaid(red_stripes, green_stripes);
//    srand(123456789);
//    auto rv = [](){ return Vec2::randomPointInUnitDiameterCircle() * 4; };
//    MobiusTransform mt0(Vec2(1,2), Vec2(0,.1), Vec2(.1,0), Vec2(1,-2), plaid);
//    MobiusTransform mt1(Vec2(-0.958788, 1.64993),
//                        Vec2(-1.54534, -0.593485),
//                        Vec2(1.29155, -0.931471),
//                        Vec2(0.768266, 0.24665),
//                        plaid);
//    rand();
//    MobiusTransform mt2(rv(), rv(), rv(), rv(), plaid);
//    rand();
//    MobiusTransform mt3(rv(), rv(), rv(), rv(), plaid);
//    MobiusTransform mt4(rv(), rv(), rv(), rv(), plaid);
//    MobiusTransform mt5(rv(), rv(), rv(), rv(), plaid);
//    //Texture::displayInWindow({ &plaid, &mt0, &mt1, &mt2, &mt3, &mt4, &mt5 });
//    Texture::displayInWindow({ &mt0, &mt5, &mt1, &mt2 });
//
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200128_";
//    mt0.writeToFile(511, path + "MobiusTransform_0");
//    mt1.writeToFile(511, path + "MobiusTransform_1");
//    mt2.writeToFile(511, path + "MobiusTransform_2");
//    mt5.writeToFile(511, path + "MobiusTransform_5");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for Scale, Feb 21, 2020
//    Spot spot1(Vec2(+0.2, 0), 0.38, Color(0.7, 0, 0), 0.4, Color());
//    Spot spot2(Vec2(-0.2, 0), 0.38, Color(0, 0, 0.7), 0.4, Color());
//    Add two_spots(spot1, spot2);
//    Scale scaled_spots(1.5, two_spots);
//    Rotate rotated_spots(pi / 4, two_spots);
//    Rotate scale_then_rotate(pi / 4, scaled_spots);
//    Translate translated_spots(Vec2(0, 0.3), two_spots);
//    Translate scale_rotate_translate(Vec2(0, 0.3), scale_then_rotate);
//    Texture::displayInWindow({
//        &two_spots,
//        &scaled_spots,
//        &rotated_spots,
//        &scale_then_rotate,
//        &translated_spots,
//        &scale_rotate_translate
//    });
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200223_";
//    two_spots.writeToFile(511, path + "two_spots");
//    scaled_spots.writeToFile(511, path + "scaled_spots");
//    scale_then_rotate.writeToFile(511, path + "scale_then_rotate");
//    scale_rotate_translate.writeToFile(511, path + "scale_rotate_translate");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    // Demo for Blur, Feb 23, 2020
//    Color b(0, 0, 0);
//    Color w(1, 1, 1);
//    //    SoftMatte(Spot(Vec2(), 0.5, w, 0.6, b),
//    //              Grating(Vec2(), w, Vec2(0.2, 0), b, 0.01),
//    //              Grating(Vec2(), w, Vec2(0, 0.2), b, 0.01)).displayInWindow();
//
//    //    SoftMatte(Spot(Vec2(), 0.6, w, 0.7, b),
//    //              Grating(Vec2(), w, Vec2(0.2, 0), b, 0.01),
//    //              Blur(0.2,
//    //                   Grating(Vec2(), w, Vec2(0, 0.2), b, 0.01))).displayInWindow();
//
//    Spot spot(Vec2(), 0.6, w, 0.7, b);
//    Grating grating1(Vec2(), w, Vec2(0.2, 0), b, 0.01);
//    Grating grating2(Vec2(), w, Vec2(0, 0.2), b, 0.01);
//    Blur blur(0.2, grating2);
//    SoftMatte no_blur(spot, grating1, grating2);
//    SoftMatte vs_blur(spot, grating1, blur);

//    auto start_time = std::chrono::high_resolution_clock::now();
//    vs_blur.displayInWindow(511, false);
//    auto finish_time = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> elapsed = finish_time - start_time;
//    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
    
//    Texture::displayInWindow({ &no_blur, &vs_blur});
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200225_";
//    no_blur.writeToFile(511, path + "no_blur");
//    vs_blur.writeToFile(511, path + "vs_blur_50_ss");

//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200226_";
//    vs_blur.writeToFile(511, path + "vs_blur");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for Colorize, February 27, 2020
//    ColorNoise for_slice(0.1, Vec2(2, 2), 0.6);
//    Brownian to_color(0.4, Vec2(), Color(0, 0, 0), Color(1, 1, 1));
//    Colorize colorized(Vec2(0, 1), Vec2(), for_slice, to_color);
//
//    Texture::displayInWindow({ &for_slice, &to_color, &colorized });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200227_";
//    for_slice.writeToFile(511, path + "for_slice");
//    to_color.writeToFile(511, path + "to_color");
//    colorized.writeToFile(511, path + "colorized");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for SoftThreshold, February 28, 2020
//    Noise grays(0.4, Vec2(), Color(0, 0, 0), Color(1, 1, 1));
//    ColorNoise colors(0.6, Vec2(), 0);
//    SoftThreshold threshold_grays(0.2, 0.7, grays);
//    SoftThreshold threshold_colors(0.4, 0.75, colors);
//    Brownian brownian(0.08, Vec2(), Color(0, 0, 0), Color(1, 1, 1));
//    SoftThreshold composition_book_cover(0.5, 0.55, brownian);
//    ColorNoise cbc(0.15, Vec2(), 0);
//    SoftThreshold color_book_cover(0.55, 0.6, cbc);
//    Texture::displayInWindow({ &grays, &threshold_grays,
//                               &colors, &threshold_colors,
//                               &composition_book_cover,
//                               &color_book_cover });
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200228_";
//    grays.writeToFile(511, path + "grays");
//    threshold_grays.writeToFile(511, path + "threshold_grays");
//    colors.writeToFile(511, path + "colors");
//    threshold_colors.writeToFile(511, path + "threshold_colors");
//    composition_book_cover.writeToFile(511, path + "composition_book_cover");
//    color_book_cover.writeToFile(511, path + "color_book_cover");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for EdgeDetect and EdgeEnhance, February 29, 2020
//
//    Noise gray_noise(0.3, Vec2(-2, 1), Color(0, 0, 0), Color(1, 1, 1));
//    SoftThreshold gray_threshold(0.5, 0.55, gray_noise);
//    Uniform light_gray(Color::gray(0.8));
//    Uniform dark_gray(Color::gray(0.2));
//    SoftMatte grays(gray_threshold, dark_gray, light_gray);
//    EdgeDetect grays_edge_detect(0.2, grays);
//    EdgeEnhance grays_edge_enhance(0.2, grays);
//
//    //Spot spot1(Vec2(+0.4, 0), 0.39, Color(0.8, 0.8, 0), 0.41, Color());
//    //Spot spot2(Vec2(-0.4, 0), 0.39, Color(0, 0.8, 0.8), 0.41, Color());
//    //Add two_spots(spot1, spot2);
//    //EdgeDetect edge_spots(0.5, two_spots);
//
//    Noise n0(0.2, Vec2(-2, +1), Color(), Color::gray(1));
//    Noise n1(0.2, Vec2(+1, +3), Color(), Color::gray(1));
//    Noise n2(0.2, Vec2(-1, -4), Color(), Color::gray(1));
//    Rotate r0(1, n0);
//    Rotate r1(3, n1);
//    Rotate r2(5, n2);
//    SoftThreshold st0(0.60, 0.64, r0);
//    SoftThreshold st1(0.60, 0.64, r1);
//    SoftThreshold st2(0.60, 0.64, r2);
//    Uniform gray50(Color::gray(0.5));
//    Uniform yellow(Color(0.8, 0.8, 0));
//    Uniform magenta(Color(0.8, 0, 0.8));
//    Uniform cyan(Color(0, 0.8, 0.8));
//    SoftMatte sm0(st0, gray50, yellow);
//    SoftMatte sm1(st1, sm0, magenta);
//    SoftMatte colors(st2, sm1, cyan);
//    EdgeDetect color_edge_detect(0.2, colors);
//    EdgeEnhance color_edge_enhance(0.2, colors);
//
//    Texture::displayInWindow({
//        &grays,
//        &grays_edge_detect,
//        &grays_edge_enhance,
//        &colors,
//        &color_edge_detect,
//        &color_edge_enhance
//    });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200301_";
//    grays.writeToFile(511, path + "grays");
//    grays_edge_detect.writeToFile(511, path + "grays_edge_detect");
//    grays_edge_enhance.writeToFile(511, path + "grays_edge_enhance");
//    colors.writeToFile(511, path + "colors");
//    color_edge_detect.writeToFile(511, path + "color_edge_detect");
//    color_edge_enhance.writeToFile(511, path + "color_edge_enhance");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for AdjustHue, March 2, 2020
//    Gradation grad(Vec2(0, -1), Color(1, 1, 1), Vec2(0, 1), Color());
//    MobiusTransform warp(Vec2(0.24665, 1.44486),
//                         Vec2(-0.184825, 1.64791),
//                         Vec2(0.391668, -1.24418),
//                         Vec2(1.04597, -0.412046),
//                         grad);
//    BrightnessToHue color1(0.7, warp);
//    AdjustHue color2(0.5, color1);
//    Texture::displayInWindow({ &color1, &color2 });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200302_";
//    color1.writeToFile(511, path + "color1");
//    color2.writeToFile(511, path + "color2");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for AdjustSaturation, March 3, 2020
//
//    ColorNoise cn(1, Vec2(2, 3), 0.8);
//    AdjustSaturation as1(0.3, cn);
//    AdjustSaturation as2(3.0, cn);
//    Texture::displayInWindow({ &cn, &as1, &as2, });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200303_";
//    cn.writeToFile(511, path + "ColorNoise");
//    as1.writeToFile(511, path + "AdjustSaturation_down");
//    as2.writeToFile(511, path + "AdjustSaturation_up");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for AdjustBrightness, March 4, 2020
//
//    ColorNoise cn(1, Vec2(2, 3), 0.8);
//    AdjustBrightness ab_down(0.5, cn);
//    AdjustBrightness ab_up(2.0, cn);
//    Texture::displayInWindow({ &cn, &ab_down, &ab_up, });
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200304_";
//    ab_down.writeToFile(511, path + "AdjustBrightness_down");
//    ab_up.writeToFile(511, path + "AdjustBrightness_up");

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Experimenting with copying Texture arguments to Operators, March 5, 2020
//
//    Color greenish(0.2, 0.8, 0.2);
//    Color bluish(0.2, 0.2, 0.8);
//    Color white(1, 1, 1);
//    Color gray10(0.1, 0.1, 0.1);
//
//    // The "no subobjects" approach:
//    Grating grate(Vec2(-0.1, -0.1), greenish, Vec2(0.1, 0.1), bluish, 0.5);
//    Furbulence furb(0.2, Vec2(3, 4), gray10, white);
//    Multiply mult(grate, furb);
//
//    // The problematic case: temp Generator objects are "destroyed" after the
//    // Operator is constructed, having saved references to the Generators.
//    Multiply trouble(Grating(Vec2(-0.1, -0.1), greenish,
//                             Vec2(+0.1, +0.1), bluish,
//                             0.5),
//                     Furbulence(0.2, Vec2(3, 4),
//                                gray10, white));
//    // The new way: allows writing an arbitrarily nested expression of TexSyn
//    // constructors, whose lifetime extends across display and file operations.
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200305_";
//    Texture::displayAndFile
//    (Grating(Vec2(-0.1, -0.1), greenish, Vec2(0.1, 0.1), bluish, 0.5),
//     path + "grating");
//    Texture::displayAndFile
//    (Furbulence(0.2, Vec2(3, 4), gray10, white),
//     path + "furbulence");
//    Texture::displayAndFile
//    (Multiply(Grating(Vec2(-0.1, -0.1), greenish, Vec2(0.1, 0.1), bluish, 0.5),
//              Furbulence(0.2, Vec2(3, 4), gray10, white)),
//     path + "fuzzy_blue_green_stripes");
//    Texture::waitKey();

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for Twist, March 6, 2020
//
//    Vec2 center(0.9, 0);
//    Color yellow9(0.9, 0.9, 0);
//    Color orange3(0.3, 0.15, 0);
//    Grating grating(Vec2(0, -0.1), orange3, Vec2(0, +0.1), yellow9, 0.3);
//    SliceToRadial radial(Vec2(0, 0.318), center, grating);
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200306_";
//    Texture::displayAndFile(radial, path + "radial");
//    Texture::displayAndFile(Twist(1, 1, center, radial), path + "Twist_1_1");
//    Texture::displayAndFile(Twist(1, 9, center, radial), path + "Twist_1_9");
//    Texture::displayAndFile(Twist(7, 1, center, radial), path + "Twist_7_1");
//    Texture::displayAndFile(Twist(7, 9, center, radial), path + "Twist_7_9");
//    Texture::waitKey();

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for BrightnessWrap, March 7, 2020
//
//    Brownian gray_noise(0.3, Vec2(-1, -3), Color(1, 1, 1), Color(0, 0, 0));
//    ColorNoise color_noise(0.5, Vec2(-1, -3), 0.6);
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200308_";
//    Texture::displayAndFile(gray_noise,
//                            path + "gray_noise");
//    Texture::displayAndFile(BrightnessWrap(0.4, 0.6, gray_noise),
//                            path + "gray_BrightnessWrap");
//    Texture::displayAndFile(color_noise,
//                            path + "color_noise");
//    Texture::displayAndFile(BrightnessWrap(0.4, 0.6, color_noise),
//                            path + "color_BrightnessWrap");
//    Texture::waitKey();

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for Mirror, March 9, 2020
//
//    Grating grating(Vec2(0.1, 0), Color(1, 1, 1),
//                    Vec2(0.3, 0), Color(0, 0, 0), 1);
//    Multiply grating_squared(grating, grating);
//    Brownian gray_noise(0.3, Vec2(-1, -3), Color(1, 1, 1), Color(0, 0, 0));
//    Colorize squiggles(Vec2(1, 0), Vec2(), grating_squared, gray_noise);
//
//    ColorNoise color_noise(0.5, Vec2(-1, -3), 0.6);
//    Multiply color_squiggles(color_noise, squiggles);
//    Uniform white(Color(1, 1, 1));
//    Subtract test(white, color_squiggles);
//
//    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200309_";
//    Texture::displayAndFile(squiggles, path + "squiggles");
//    Texture::displayAndFile(test, path + "test");
//    Texture::displayAndFile(Mirror(Vec2(0, 1), Vec2(), test),
//                            path + "Mirror_y");
//    Texture::displayAndFile(Mirror(Vec2(1, 0),
//                                   Vec2(),
//                                   Mirror(Vec2(0, 1), Vec2(), test)),
//                            path + "Mirror_y_then_x");
//    Texture::waitKey();

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for using "lambda combination" to bind nested texture definitions
//    // for the duration of the demo code, March 10, 2020
//    Grating grating(Vec2(0.1, 0), Color(1, 1, 1),
//                    Vec2(0.3, 0), Color(0, 0, 0), 1);
//    []
//    (const Texture& test)
//    {
//        Texture::displayAndFile(test);
//        Texture::displayAndFile(Mirror(Vec2(0, 1), Vec2(), test));
//        Texture::displayAndFile(Mirror(Vec2(1, 0),
//                                       Vec2(),
//                                       Mirror(Vec2(0, 1), Vec2(), test)));
//        Texture::waitKey();
//    }
//    (Subtract(Uniform(Color(1, 1, 1)),
//              Multiply(ColorNoise(0.5, Vec2(-1, -3), 0.6),
//                       Colorize(Vec2(1, 0),
//                                Vec2(),
//                                Multiply(grating, grating),
//                                Brownian(0.3, Vec2(-1, -3),
//                                         Color(1, 1, 1),
//                                         Color(0, 0, 0))))));

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for Ring, March 11, 2020
//    Color white(1, 1, 1);
//    Color black(0, 0, 0);
//    Spot spot(Vec2(0, -0.05), 0.19, white, 0.20, black);
//    [&]
//    (const Texture& bg)
//    {
//        [&]
//        (const Texture& spots_and_bg)
//        {
//            std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200311_";
//            Texture::displayAndFile(spots_and_bg, path + "spots_and_bg");
//            Texture::displayAndFile(Ring(10.1,
//                                         Vec2(0, 1),
//                                         Vec2(0, -0.9),
//                                         spots_and_bg),
//                                    path + "Ring_1");
//            Texture::displayAndFile(Ring(-4.8,
//                                         Vec2(1, 1),
//                                         Vec2(-1, -1).normalize() / 2,
//                                         spots_and_bg),
//                                    path + "Ring_2");
//            Texture::waitKey();
//        }
//        (SoftMatte(Translate(Vec2(0, 0.1), spot),
//                   SoftMatte(spot, bg, AdjustBrightness(0.8, bg)),
//                   Uniform(Color::gray(0.8))));
//    }
//    (AdjustBrightness(0.7,
//                      AdjustSaturation(0.1,
//                                       ColorNoise(0.5, Vec2(-1, -3),  0.6))));

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//    // Demo for Row, March 12, 2020
//    Color white(1, 1, 1);
//    Color black(0, 0, 0);
//    Spot spot(Vec2(0, -0.05), 0.19, white, 0.20, black);
//    [&]
//    (const Texture& bg)
//    {
//        [&]
//        (const Texture& spots_and_bg)
//        {
//            std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200312_";
//            Texture::displayAndFile(spots_and_bg);
//            Texture::displayAndFile(Row(Vec2(0.4, 0),
//                                        Vec2(),
//                                        spots_and_bg),
//                                    path + "row_1");
//            Texture::displayAndFile(Row(Vec2(0.35, 0.35),
//                                        Vec2(),
//                                        spots_and_bg),
//                                    path + "row_2");
//            Texture::displayAndFile(Row(Vec2(0, 0.6),
//                                        Vec2(),
//                                        spots_and_bg),
//                                    path + "row_3");
//            Texture::displayAndFile(Row(Vec2(0.17, 0.52),
//                                        Vec2(),
//                                        Row(Vec2(-0.52, 0.17),
//                                            Vec2(),
//                                            spots_and_bg)),
//                                    path + "row_4");
//            Texture::waitKey();
//        }
//        (SoftMatte(Translate(Vec2(0, 0.1), spot),
//                   SoftMatte(spot, bg, AdjustBrightness(0.8, bg)),
//                   Uniform(Color::gray(0.8))));
//    }
//    (AdjustBrightness(0.7,
//                      AdjustSaturation(0.1,
//                                       ColorNoise(0.5, Vec2(-1, -3),  0.6))));

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//    // playing with spots, March 12, 2020
//    Color white(1, 1, 1);
//    Color black(0, 0, 0);
//    Texture::displayAndFile
//    (SoftThreshold(0.5, 0.6, Noise(0.05, Vec2(5, 2), white, black)));
//    Texture::displayAndFile
//    (SoftThreshold(0.5, 0.6, Brownian(0.05, Vec2(5, 2), white, black)));
//    Texture::displayAndFile
//    (SoftThreshold(0.50,
//                   0.55,
//                   Blur(0.1,
//                        Brownian(0.05, Vec2(5, 2), white, black))));
//    Texture::displayAndFile
//    (SoftThreshold(0.7,
//                   0.8,
//                   Max(Rotate(2, Noise(0.1, Vec2(5, 2), white, black)),
//                       Rotate(4, Noise(0.1, Vec2(2, 5), white, black)))));
//    Texture::waitKey();
    
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

/*
    // cache for Blur? -- March 13, 2020
    // note: see "chrono" above for timing
    //
    Color white(1, 1, 1);
    Color black(0, 0, 0);
    Color yellow(1, 1, 0);
    Color blue(0, 0, 1);
    [&]
    (const Texture& blur_vs_not)
    {
        ColorGridCache cgc;
        bool present_in_cache = false;
        
        debugPrint(cgc.cached(1, 1));
        cgc.insert(1, 1, Color(1,2,3));
//        debugPrint(cgc.insert(1, 1, Color(1,2,3)));
        debugPrint(cgc.cached(1, 1));
        debugPrint(present_in_cache);
        debugPrint(cgc.lookup(1, 1, present_in_cache));
        debugPrint(present_in_cache);

        
        
        
        
        std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200317_";
        
//        {
//            Timer blur_timer("Running blur_vs_not");
//            Texture::displayAndFile(blur_vs_not);
//        }

        
//        Texture::displayAndFile(Grating(Vec2(), white,
//                                        Vec2(0.2, 0.2), black,
//                                        0.01)
//                                // , path + "grating"
//                                );
        {
            Timer blur_timer("Running Blur(Grating(...))");
            Texture::total_pixels_rendered = 0;
            Texture::total_pixels_cached = 0;
            Texture::total_cache_lookups = 0;
            Texture::cache_size = 0;
            
            Texture::displayAndFile(Blur(0.2,
//            Texture::displayAndFile(Blur(0.5,
                                         Grating(Vec2(), yellow,
                                                 Vec2(0.2, 0.2), blue,
                                                 0.01))
//                                     , path + "Blur_newer_yb_02"
//                                    , path + "Blur_newer_yb_05"
//                                    , path + "Blur_old_yb_05"
//                                    , path + "Blur_old_yb_02_10x10"
//                                    , path + "Blur_old_yb_02_11x11"
//                                    , path + "Blur_old_yb_02_15x15"
                                    );
            
            debugPrint(Texture::total_pixels_rendered);
            debugPrint(Texture::total_pixels_cached);
            debugPrint(Texture::total_cache_lookups);
            debugPrint(Texture::cache_size);
        }

        Texture::displayAndFile(EdgeDetect(0.2,
//        Texture::displayAndFile(EdgeDetect(0.5,
                                           Grating(Vec2(), yellow,
                                                   Vec2(0.2, 0.2), blue,
                                                   0.01))
//                                , path + "EdgeD_newer_yb_02"
//                                , path + "EdgeD_newer_yb_05"
//                                , path + "EdgeD_old_yb_02"
                                );
        
        Texture::waitKey();
    }
    (SoftMatte(Spot(Vec2(), 0.6, white, 0.7, black),
               Grating(Vec2(), white, Vec2(0.2, 0), black, 0.01),
               Blur(0.2,
                    Grating(Vec2(), white, Vec2(0, 0.2), black, 0.01))));
    
*/
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Demo for hashing and RandomSequence, March 19, 2020

//    debugPrint(hash_float(0.000000));
//    debugPrint(hash_float(0.000001));
//    debugPrint(hash_float(100000.0));
//    debugPrint(hash_float(1123.456));
//    debugPrint(hash_float(123456.7));
//
//    debugPrint(Vec2(0, 0).hash());
//    debugPrint(Vec2(5, 7).hash());
//    debugPrint(Vec2(7, 5).hash());
//    debugPrint(Vec2(-8, 3).hash());
//    debugPrint(Vec2(3, -8).hash());
//
//    RandomSequence rs; for (int i = 0; i < 20; i++) debugPrint(rs.nextInt());
//
//    Color yellow(1, 1, 0);
//    Color blue(0, 0, 1);
//    Texture::diff(Blur(0.2, Grating(Vec2(), yellow, Vec2(0.2, 0.2), blue, 0.01)),
//                  Blur(0.2, Grating(Vec2(), yellow, Vec2(0.2, 0.2), blue, 0.01)));
//    Texture::waitKey();

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // Demo for SliceShear, started Jan 25, 2020, restarted March 20, 2020

    Color white(1, 1, 1);
    Color black(0, 0, 0);
    Color orange(1, 0.5, 0);
    Color cyan_blue(0, 0.5, 1);
    Color gray = Color::gray(0.3);

    // Horizontal stripes -- to be sheared.
    Grating to_shear(Vec2(), orange, Vec2(0, 0.25), cyan_blue, 0.4);

    // For slice: noise in one direction, square wave in other direction
    Brownian b1(0.1, Vec2(), black, gray);
    SliceGrating sg1(Vec2(1, 0), Vec2(), b1);
    Grating g1(Vec2(), black, Vec2(0, 0.1), gray, 0.2);
    Add for_slice(sg1, g1);

    std::string path = "/Users/cwr/Desktop/TexSyn_temp/20200321_";
    Texture::displayAndFile(for_slice, path + "for_slice");
    Texture::displayAndFile(to_shear, path + "to_shear");
    Texture::displayAndFile(SliceShear(Vec2(1, 0), Vec2(), for_slice,
                                       Vec2(0, 1), Vec2(), to_shear),
                            path + "SliceShear_1");
    Texture::displayAndFile(SliceShear(Vec2(0, 1), Vec2(), for_slice,
                                       Vec2(0, 1), Vec2(), to_shear),
                            path + "SliceShear_2");
    Texture::displayAndFile(SliceShear(Vec2(1, 0), Vec2(), for_slice,
                                       Vec2(1, 1), Vec2(), to_shear),
                            path + "SliceShear_3");
    Texture::waitKey();

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    return EXIT_SUCCESS;
}
