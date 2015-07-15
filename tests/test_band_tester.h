#include "colour_chart_test.h"
#include "../lib/display.h"
#include "../lib/band_tester.h"

#include <stdio.h>

int test_band_tester_constructor()
{
    ColourFormat_RGB565 test_cfs[4];

    test_cfs[0].set_colour(0xffff);
    test_cfs[1].set_colour(0xffff);
    test_cfs[2].set_colour(0xffff);
    test_cfs[3].set_colour(0xffff);

    Display test_display;

    BandTester test_bt(test_display, test_cfs);

    test_bt.draw_screen();

    uint16_t *fb = get_frame_buffer();

    if (fb[0] != 0xffff) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_BAND_TESTER_CONSTRUCTOR);
        return 0;
    }

    return 1;
}

int test_band_tester_two_corner_gradient()
{
    ColourFormat_RGB565 test_cfs[4];

    test_cfs[0].set_colour(0xf);
    test_cfs[1].set_colour(0x0);
    test_cfs[2].set_colour(0xf);
    test_cfs[3].set_colour(0x0);

    Display test_display;

    BandTester test_bt(test_display, test_cfs);

    test_bt.draw_screen();

    uint16_t *fb = get_frame_buffer();

    if (fb[8] != 0x7) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_BAND_TESTER_TWO_CORNER_GRADIENT);
        return 0;
    }

    return 1;
}

int test_band_tester_four_corner_gradient()
{
    ColourFormat_RGB565 test_cfs[4];

    test_cfs[0].set_colour(0xf);
    test_cfs[1].set_colour(0x0);
    test_cfs[2].set_colour(0x7e0);
    test_cfs[3].set_colour(0xf800);

    int w, h;
    Display test_display;
    test_display.get_size(w, h);

    BandTester test_bt(test_display, test_cfs);

    test_bt.draw_screen();

    uint16_t *fb = get_frame_buffer();

    if (fb[0] != 0xf || fb[w-1] != 0x0 || fb[(h-1)*w] != 0x7e0 || fb[w*h -1] != 0xf800) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_BAND_TESTER_FOUR_CORNER_GRADIENT);
        return 0;
    }

    return 1;
}
