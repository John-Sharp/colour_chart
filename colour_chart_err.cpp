#include "colour_chart_err.h"

void colour_chart_raise_error(colour_chart_errno error)
{
    colour_chart_current_errno = error;
}

int colour_chart_get_error()
{
    return colour_chart_current_errno;
}

void colour_chart_reset_error()
{
    colour_chart_current_errno = 0;
}

const char * const colour_chart_strerror()
{
    return colour_chart_error_messages[colour_chart_current_errno];
}
