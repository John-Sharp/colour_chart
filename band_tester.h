#ifndef BAND_TESTER_H
#define BAND_TESTER

#include "colour_chart_constants.h"
#include "display.h"
#include "colour_format.h"

class BandTester {
public:
    BandTester(
        Display &display,
        const ColourFormat *corner_colours_arg);
    void draw_screen();

private:
    Display *display;
    ColourFormat corner_colours[NUM_TEST_POINTS];
    double gradients[2][NUM_COLOUR_CHANNELS];
    void calculate_gradients();
    void draw_line();
};

#endif
