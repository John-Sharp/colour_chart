#ifndef COLOUR_CHART_TEST_H
#define COLOUR_CHART_TEST_H

struct colour_chart_unit_test {
    const char * const test_name;
    int (*test_fn)();
};

enum colour_chart_test_errno {
    COLOUR_CHART_ERR_NO_ERROR,
    COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_CONSTRUCTOR,
    COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_SET_BY_BF,
    COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_SET_BY_NORM,
    COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_SET_BY_ARGS,
    COLOUR_CHART_TEST_ERR_BAND_TESTER_CONSTRUCTOR,
    COLOUR_CHART_TEST_ERR_BAND_TESTER_TWO_CORNER_GRADIENT,
    COLOUR_CHART_TEST_ERR_BAND_TESTER_FOUR_CORNER_GRADIENT
};

const char * const colour_chart_test_error_messages[] = {
    "",
    "Colour format constructor is not intitialising properly",
    "ColourFormat::set_colour by bitfield not functioning correctly",
    "ColourFormat::set_colour by ColourNorm not functioning correctly",
    "ColourFormat::set_colour by individual components not functioning correctly",
    "BandTester constructor is not initialising properly",
    "BandTester gradient incorrect for two corners",
    "BandTester gradient incorrect for four corners"
};

static unsigned int colour_chart_test_current_errno = 0;

void colour_chart_test_raise_error(colour_chart_test_errno error);
const char * const colour_chart_test_strerror();

#include "test_colour_format.h"
#include "test_band_tester.h"

const colour_chart_unit_test unit_tests[] = {
    {"tests/test_colour_format.h: test_colour_format_constructor1", test_colour_format_constructor1},
    {"tests/test_colour_format.h: test_colour_format_constructor2", test_colour_format_constructor2},
    {"tests/test_colour_format.h: test_colour_format_constructor3", test_colour_format_constructor3},
    {"tests/test_colour_format.h: test_colour_format_set_colour1", test_colour_format_set_colour1},
    {"tests/test_colour_format.h: test_colour_format_set_colour2", test_colour_format_set_colour2},
    {"tests/test_colour_format.h: test_colour_format_set_colour3", test_colour_format_set_colour3},
    {"tests/test_band_tester.h: test_band_tester_constructor", test_band_tester_constructor},
    {"tests/test_band_tester.h: test_band_tester_two_corner_gradient", test_band_tester_two_corner_gradient},
    {"tests/test_band_tester.h: test_band_tester_four_corner_gradient", test_band_tester_four_corner_gradient}
};

#endif
