#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"

struct Game{
    Window *win;
    Game(Window *w);
    void loop();
    void draw();
};


#endif//GAME_HPP
