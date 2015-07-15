all: main.cpp colour_format.cpp colour_format.h \
	colour_chart_err.h colour_chart_err.cpp \
	input_parser.h input_parser.cpp \
	display.h display.cpp \
	band_tester.h band_tester.cpp
	g++ main.cpp colour_format.cpp colour_chart_err.cpp \
		input_parser.cpp display.cpp band_tester.cpp -o colour_chart
