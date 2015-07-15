#include "input_parser.h" 

#include "colour_chart_err.h"

#include <string.h>
#include <stdio.h>

unsigned int parse_int(const char *s)
{
    unsigned int arg_i;

    if (strlen(s) >= 2 && s[0] == '0' && s[1] == 'x') {
        sscanf(s, "%x", &arg_i);
    } else if (strlen(s) >= 1 && s[0] >= '0' && s[0] <= '9') {
       sscanf(s, "%u", &arg_i); 
    } else {
        colour_chart_raise_error(COLOUR_CHART_ERR_CALLING_ARGS);
        return 0;
    }

    return arg_i;
}

ColourFormat *parse_input_colours(
    int argv,
    char **argc,
    ColourFormat *corner_colours)
{
    if (argv < 4) {
        colour_chart_raise_error(COLOUR_CHART_ERR_CALLING_ARGS);
        return NULL;
    }

    if (colour_chart_get_error() != 0) {
        return NULL;
    }

    int num_test_colours = argv - 2;

    unsigned int tc_tl = parse_int(argc[2]);
    unsigned int tc_tr = parse_int(argc[3]);
    unsigned int tc_bl = tc_tl;
    unsigned int tc_br = tc_tr;

    if (colour_chart_get_error() != 0) {
        return NULL;
    }

    if (num_test_colours >= 3) {
        tc_bl = parse_int(argc[4]);
    }
    if (num_test_colours >= 4) {
        tc_br = parse_int(argc[5]);
    }

    corner_colours[0].set_colour(tc_tl);
    corner_colours[1].set_colour(tc_tr);
    corner_colours[2].set_colour(tc_bl);
    corner_colours[3].set_colour(tc_br);

    return corner_colours;
}

const char *parse_input_display_name(
    int argv,
    char **argc,
    const char **display_name)
{
    *display_name = argc[1];
    return *display_name;
}
