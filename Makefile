all: src/main.cpp lib/colour_format.cpp lib/colour_format.h \
	lib/colour_chart_err.h lib/colour_chart_err.cpp \
	lib/input_parser.h lib/input_parser.cpp \
	lib/display.h lib/display.cpp \
	lib/band_tester.h lib/band_tester.cpp
	g++ -std=c++98 -lm src/main.cpp lib/colour_format.cpp lib/colour_chart_err.cpp \
		lib/input_parser.cpp lib/display.cpp lib/band_tester.cpp -o bin/ramp.exe

tests: tests/colour_chart_test.cpp lib/colour_format.h \
	lib/colour_format.cpp lib/band_tester.h lib/band_tester.cpp \
	lib/display.h lib/display.cpp
	g++ -std=c++98 -lm tests/colour_chart_test.cpp lib/colour_format.cpp \
		lib/band_tester.cpp lib/display.cpp -o bin/tests.exe
