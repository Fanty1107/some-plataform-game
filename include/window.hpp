#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <raylib.h>

struct Window{
    int width;
    int height;
    const char *title;
    Window(int w, int h, const char *t);
    ~Window();
};


#endif//WINDOW_HPP
