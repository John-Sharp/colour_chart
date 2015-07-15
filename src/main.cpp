#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

#include "../lib/colour_chart_constants.h"
#include "../lib/colour_format.h"
#include "../lib/colour_chart_err.h"
#include "../lib/input_parser.h"
#include "../lib/display.h"
#include "../lib/band_tester.h"

int main(int argv, char **argc)
{
    ColourFormat_RGB565 corner_colours[NUM_TEST_POINTS];
    parse_input_colours(argv, argc, corner_colours);
    if (colour_chart_get_error() != 0) {
        std::cerr << colour_chart_strerror();
        return -1;
    }

    const char *display_name;
    parse_input_display_name(argv, argc, &display_name);

    Display test_display;
    if (!test_display.connect(display_name)) {
        colour_chart_raise_error(COLOUR_CHART_ERR_DISPLAY_CONNECTION);
        std::cerr << colour_chart_strerror();
        return -1;
    }

    BandTester bt(test_display, corner_colours);

    bt.draw_screen();
}
