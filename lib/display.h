#ifndef DISPLAY_H
#define DISPLAY_H
class Display {
public:
	Display();
	~Display();
	bool connect(const char *display_name);
	void get_size(int &width, int &height);
	void draw_raster(int x, int y,
              const unsigned short *pixels, int width);
};

unsigned short *get_frame_buffer();
#endif
