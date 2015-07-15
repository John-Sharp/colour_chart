#include "colour_chart_test.h"
#include "../lib/colour_format.h"
#include <stdio.h>

int test_colour_format_constructor1()
{
    BitfieldDesc bf1 = {11, 5};
    BitfieldDesc bf2 = {5, 6};
    BitfieldDesc bf3 = {0, 5};
    ColourFormat test_cf(bf1, bf2, bf3);

    if (test_cf.r_bf_desc.offset != 11 
            || test_cf.r_bf_desc.width != 5
            || test_cf.g_bf_desc.offset != 5
            || test_cf.g_bf_desc.width != 6
            || test_cf.b_bf_desc.offset != 0
            || test_cf.b_bf_desc.width != 5
       ) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_CONSTRUCTOR);
        return 0;
    }

    return 1;
}

int test_colour_format_constructor2()
{
    ColourFormat test_cf(11, 5, 5, 6, 0, 5);

    if (test_cf.r_bf_desc.offset != 11 
            || test_cf.r_bf_desc.width != 5
            || test_cf.g_bf_desc.offset != 5
            || test_cf.g_bf_desc.width != 6
            || test_cf.b_bf_desc.offset != 0
            || test_cf.b_bf_desc.width != 5
       ) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_CONSTRUCTOR);
        return 0;
    }

    return 1;
}

int test_colour_format_constructor3()
{
    ColourFormat test_cf;

    if (test_cf.r_bf_desc.offset != 0
            || test_cf.r_bf_desc.width != 0
            || test_cf.g_bf_desc.offset != 0
            || test_cf.g_bf_desc.width != 0
            || test_cf.b_bf_desc.offset != 0
            || test_cf.b_bf_desc.width != 0
       ) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_CONSTRUCTOR);
        return 0;
    }

    return 1;
}

int test_colour_format_set_colour1()
{
    ColourFormat test_cf(11, 5, 5, 6, 0, 5);

    test_cf.set_colour(0xf800);



    if (test_cf.colour_norm.r != 1.0f 
            || test_cf.colour_norm.g != 0.0f
            || test_cf.colour_norm.b != 0.0f
       ) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_SET_BY_BF);
        return 0;
    }

    return 1;
}

int test_colour_format_set_colour2()
{
    ColourFormat test_cf(11, 5, 5, 6, 0, 5);
    ColourNorm test_colour = {0.0f, 1.0f, 0.0f};

    test_cf.set_colour(test_colour);

    if (test_cf.colour_bf != 0x7e0) {
        fprintf(stderr, "%x\n", test_cf.colour_bf);
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_SET_BY_NORM);
        return 0;
    }

    return 1;
}

int test_colour_format_set_colour3()
{
    ColourFormat test_cf(11, 5, 5, 6, 0, 5);
    test_cf.set_colour(0.0f, 1.0f, 1.0f);

    if (test_cf.colour_bf != 0x7e0 + 0x1f) {
        colour_chart_test_raise_error(
                COLOUR_CHART_TEST_ERR_COLOUR_FORMAT_SET_BY_ARGS);
        return 0;
    }

    return 1;
}
