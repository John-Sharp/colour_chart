#include <iostream>
#include <stdio.h>
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

    int w, h;
    display.get_size(w, h);

    pixel_line = new uint16_t[w];

    calculate_gradients();
}

BandTester::~BandTester()
{
    delete pixel_line;
}

void BandTester::draw_screen()
{
    int w, h;

    display->get_size(w, h);

    for (unsigned int i = 0; i < h; i++) {
        draw_line(i);
    }
}

void BandTester::calculate_gradients()
{
    int w, h;

    display->get_size(w, h);

    double start_y_screen = 0.5;
    double end_y_screen = static_cast<double>(h) - 0.5;

    gradients[GRAD_LEFT_DOWN][R] = (corner_colours[BL].colour_norm.r -
        corner_colours[TL].colour_norm.r) / 
        (end_y_screen - start_y_screen);

    gradients[GRAD_RIGHT_DOWN][R] = (corner_colours[BR].colour_norm.r -
        corner_colours[TR].colour_norm.r) / 
        (end_y_screen - start_y_screen);

    gradients[GRAD_LEFT_DOWN][B] = (corner_colours[BL].colour_norm.b -
        corner_colours[TL].colour_norm.b) / 
        (end_y_screen - start_y_screen);

    gradients[GRAD_RIGHT_DOWN][B] = (corner_colours[BR].colour_norm.b -
        corner_colours[TR].colour_norm.b) / 
        (end_y_screen - start_y_screen);

    gradients[GRAD_LEFT_DOWN][G] = (corner_colours[BL].colour_norm.g -
        corner_colours[TL].colour_norm.g) / 
        (end_y_screen - start_y_screen);

    gradients[GRAD_RIGHT_DOWN][G] = (corner_colours[BR].colour_norm.g -
        corner_colours[TR].colour_norm.g) / 
        (end_y_screen - start_y_screen);
}

void BandTester::draw_line(unsigned int line_no)
{
    ColourNorm start_colour = corner_colours[TL].colour_norm;
    start_colour.r += gradients[GRAD_LEFT_DOWN][R] * static_cast<double>(line_no);
    start_colour.g += gradients[GRAD_LEFT_DOWN][G] * static_cast<double>(line_no);
    start_colour.b += gradients[GRAD_LEFT_DOWN][B] * static_cast<double>(line_no);

    ColourNorm end_colour = corner_colours[TR].colour_norm;
    end_colour.r += gradients[GRAD_RIGHT_DOWN][R] * static_cast<double>(line_no);
    end_colour.g += gradients[GRAD_RIGHT_DOWN][G] * static_cast<double>(line_no);
    end_colour.b += gradients[GRAD_RIGHT_DOWN][B] * static_cast<double>(line_no);

    ColourFormat pixel_colour = corner_colours[TL];

    int w, h;

    display->get_size(w, h);

    double start_x_screen = 0.5;
    double end_x_screen = static_cast<double>(w) - 0.5;

    double horizontal_gradient[NUM_COLOUR_CHANNELS];
    horizontal_gradient[R] = (end_colour.r - start_colour.r) / (end_x_screen - start_x_screen);
    horizontal_gradient[G] = (end_colour.g - start_colour.g) / (end_x_screen - start_x_screen);
    horizontal_gradient[B] = (end_colour.b - start_colour.b) / (end_x_screen - start_x_screen);

    for (unsigned int i = 0; i < w; i++) {
        pixel_colour.set_colour(
            start_colour.r + i * horizontal_gradient[R], 
            start_colour.g + i * horizontal_gradient[G], 
            start_colour.b + i * horizontal_gradient[B]); 
        pixel_line[i] = pixel_colour.colour_bf;
    }

    display->draw_raster(0, line_no, pixel_line, w);
}
