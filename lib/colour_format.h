#ifndef COLOUR_FORMAT_H
#define COLOUR_FORMAT_H

#include <stdint.h>

struct BitfieldDesc {
    unsigned int offset;
    unsigned int width;
};

struct ColourNorm {
    double r;
    double g;
    double b;
};

class ColourFormat {
public:
    ColourFormat(
        BitfieldDesc r_bf_desc,
        BitfieldDesc g_bf_desc,
        BitfieldDesc b_bf_desc);

    ColourFormat(
        unsigned int r_bf_offset,
        unsigned int r_bf_width,
        unsigned int g_bf_offset,
        unsigned int g_bf_width,
        unsigned int b_bf_offset,
        unsigned int b_bf_width);

    ColourFormat();

    void set_colour(uint16_t colour);
    void set_colour(ColourNorm colour);
    void set_colour(double r, double g, double b);

    void get_colour_bf();
    void get_colour_norm();

    BitfieldDesc r_bf_desc;
    BitfieldDesc g_bf_desc;
    BitfieldDesc b_bf_desc;
    uint16_t colour_bf;
    ColourNorm colour_norm;
private:
    double get_norm_from_bf(BitfieldDesc &bf_desc);
    uint16_t get_bf_cmpt_from_norm_cmpt(double norm_cmpt, const BitfieldDesc &bf_desc);
    void set_bf_from_norm();
};

class ColourFormat_RGB565 : public ColourFormat {
public:
    ColourFormat_RGB565();
};

#endif
