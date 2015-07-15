#ifndef COLOUR_CHART_ERR_H
#define COLOUR_CHART_ERR_H

static unsigned int colour_chart_current_errno = 0;

enum colour_chart_errno {
    COLOUR_CHART_ERR_NO_ERROR,
    COLOUR_CHART_ERR_CALLING_ARGS,
    COLOUR_CHART_ERR_DISPLAY_CONNECTION
};

const char * const colour_chart_error_messages[] = {
    "",
    "Program usage: ramp.exe display tl tr [bl] [br]",
    "Error! Problem connecting with display"

};

int colour_chart_get_error();
void colour_chart_reset_error();
void colour_chart_raise_error(colour_chart_errno error);
const char * const colour_chart_strerror();


#endif
