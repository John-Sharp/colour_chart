#include <iostream>
#include <string.h>
#include "band_tester.h"

BandTester::BandTester(
    Display &display,
    const ColourFormat *corner_colours_arg) :
    display(&display)
{
    memcpy(
        corner_colours,
        corner_colours_arg,
        NUM_TEST_POINTS * sizeof(*corner_colours));

    calculate_gradients();
}

void BandTester::draw_screen()
{
}

void BandTester::calculate_gradients()
{
    int w, h;

    display->get_size(w, h);

    double start_x_screen = 0.5;
    double end_x_screen = static_cast<double>(w) - 0.5;

    double start_y_screen = 0.5;
    double end_y_screen = static_cast<double>(h) - 0.5;

    std::cerr << "Red right: from (0.5, " << corner_colours[TL].colour_norm.r
        << ") to (" << static_cast<double>(w) - 0.5
        << ", " << corner_colours[TR].colour_norm.r << ")\n";

    std::cerr << "Red down: from (0.5, " << corner_colours[TL].colour_norm.r
        << ") to (" << static_cast<double>(w) - 0.5
        << ", " << corner_colours[BL].colour_norm.r << ")\n";

    gradients[GRAD_RIGHT][R] = (corner_colours[TR].colour_norm.r -
        corner_colours[TL].colour_norm.r) / 
        (end_x_screen - start_x_screen);

    gradients[GRAD_DOWN][R] = (corner_colours[TR].colour_norm.r -
        corner_colours[BR].colour_norm.r) / 
        (end_x_screen - start_x_screen);


    gradients[GRAD_RIGHT][G] = (corner_colours[TR].colour_norm.g -
        corner_colours[TL].colour_norm.g) / 
        (end_x_screen - start_x_screen);

    gradients[GRAD_DOWN][G] = (corner_colours[TR].colour_norm.g -
        corner_colours[BR].colour_norm.g) / 
        (end_x_screen - start_x_screen);


    gradients[GRAD_RIGHT][B] = (corner_colours[TR].colour_norm.b -
        corner_colours[TL].colour_norm.b) / 
        (end_x_screen - start_x_screen);

    gradients[GRAD_DOWN][B] = (corner_colours[TR].colour_norm.b -
        corner_colours[BR].colour_norm.b) / 
        (end_x_screen - start_x_screen);

    std::cerr << "Grad horiz\n";
    std::cerr << "R: " << gradients[GRAD_RIGHT][R];
    std::cerr << " G: " << gradients[GRAD_RIGHT][G];
    std::cerr << " B: " << gradients[GRAD_RIGHT][B];
    std::cerr << '\n';

    std::cerr << "Grad vert\n";
    std::cerr << "R: " << gradients[GRAD_DOWN][R];
    std::cerr << " G: " << gradients[GRAD_DOWN][G];
    std::cerr << " B: " << gradients[GRAD_DOWN][B];
    std::cerr << '\n';
}

void BandTester::draw_line()
{
}

