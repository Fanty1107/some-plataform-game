#include "game.hpp"

Game::Game(Window *w) : win(w){}

void Game::draw(){
    BeginDrawing();
        ClearBackground(BLACK);
    EndDrawing();
}
void Game::loop(){
    while(!WindowShouldClose()){
        draw();
    }
}
