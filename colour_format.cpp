#include "colour_format.h"

ColourFormat::ColourFormat(
    BitfieldDesc r_bf_desc,
    BitfieldDesc g_bf_desc,
    BitfieldDesc b_bf_desc) :
        r_bf_desc(r_bf_desc),
        g_bf_desc(g_bf_desc),
        b_bf_desc(b_bf_desc)
{
    set_colour(0);
}

ColourFormat::ColourFormat(
        unsigned int r_bf_offset,
        unsigned int r_bf_width,
        unsigned int g_bf_offset,
        unsigned int g_bf_width,
        unsigned int b_bf_offset,
        unsigned int b_bf_width)
{
    r_bf_desc.offset = r_bf_offset;
    r_bf_desc.width = r_bf_width;
    g_bf_desc.offset = g_bf_offset;
    g_bf_desc.width = g_bf_width;
    b_bf_desc.offset = b_bf_offset;
    b_bf_desc.width = b_bf_width;
    set_colour(0);
}

ColourFormat::ColourFormat()
{
    r_bf_desc.offset = 0;
    r_bf_desc.width = 0;
    g_bf_desc.offset = 0;
    g_bf_desc.width = 0;
    b_bf_desc.offset = 0;
    b_bf_desc.width = 0;
    set_colour(0);
}

double ColourFormat::get_norm_from_bf(BitfieldDesc &bf_desc)
{
    uint16_t colour_temp = colour_bf;

    uint16_t colour_max = ((1 << bf_desc.width) - 1);
    colour_temp = colour_temp >> bf_desc.offset;
    colour_temp &= colour_max;

    return static_cast<double>(colour_temp) /
        static_cast<double>(colour_max);
}

void ColourFormat::set_colour(uint16_t colour)
{
    colour_bf = colour;
    colour_norm.r = get_norm_from_bf(r_bf_desc);
    colour_norm.g = get_norm_from_bf(g_bf_desc);
    colour_norm.b = get_norm_from_bf(b_bf_desc);
}

void ColourFormat::set_colour(ColourNorm colour)
{
    colour_bf = 0;
    colour_norm.r = 0.0f;
    colour_norm.g = 0.0f;
    colour_norm.b = 0.0f;
}

ColourFormat_RGB565::ColourFormat_RGB565() :
    ColourFormat(
        11, // offset red
        5, // width red
        5, // offset green
        6, //width green
        0, // offset blue
        5) // width blue
{}

