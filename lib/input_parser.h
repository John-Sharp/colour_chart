#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "colour_format.h"

unsigned int parse_int(const char *s);

ColourFormat *parse_input_colours(
    int argv,
    char **argc,
    ColourFormat *corner_colours);

const char *parse_input_display_name(
    int argv,
    char **argc,
    const char **display_name);

#endif
