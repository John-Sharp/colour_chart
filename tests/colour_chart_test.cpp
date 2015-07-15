#include <iostream>

#include "colour_chart_test.h"

void colour_chart_test_raise_error(colour_chart_test_errno error)
{
    colour_chart_test_current_errno = error;
}

const char * const colour_chart_test_strerror()
{
    return colour_chart_test_error_messages[colour_chart_test_current_errno];
}

int main(int argv, char **argc)
{
    unsigned int num_tests = sizeof(unit_tests) / sizeof(colour_chart_unit_test);
    
    for (unsigned int i = 0; i < num_tests; i++) {
        if (!unit_tests[i].test_fn()) {
            std::cerr << "Failure in test: \"" << unit_tests[i].test_name << "\": ";
            std::cerr << colour_chart_test_strerror() << '\n';
            return 1;
        }
    }

    std::cerr << "Tests passed" << '\n';
    return 0;
}
