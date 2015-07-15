#include "colour_format.h"
#include "math.h"

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
    colour_norm.r = colour.r;
    colour_norm.g = colour.g;
    colour_norm.b = colour.b;

    set_bf_from_norm();
}

void ColourFormat::set_colour(double r, double g, double b)
{
    colour_norm.r = r;
    colour_norm.g = g;
    colour_norm.b = b;

    set_bf_from_norm();
}

uint16_t ColourFormat::get_bf_cmpt_from_norm_cmpt(double norm_cmpt, const BitfieldDesc &bf_desc)
{
    double scale_factor = static_cast<double>((1 << bf_desc.width)-1);
    uint16_t bf_cmpt = static_cast<int>(round(norm_cmpt * scale_factor));
    bf_cmpt = bf_cmpt << bf_desc.offset;
    return bf_cmpt;
}

void ColourFormat::set_bf_from_norm()
{
    colour_bf = get_bf_cmpt_from_norm_cmpt(colour_norm.r, r_bf_desc);
    colour_bf += get_bf_cmpt_from_norm_cmpt(colour_norm.g, g_bf_desc);
    colour_bf += get_bf_cmpt_from_norm_cmpt(colour_norm.b, b_bf_desc);
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

