#include "log.hpp"
#include "window.hpp"
#include "game.hpp"



int main(){
    Window w(800,800,"Teste");
    Game g(&w);
    g.loop();
    LOG::PRINT("Exit Sucess", LOG::LEVEL::LOW);
    return 0;
}
