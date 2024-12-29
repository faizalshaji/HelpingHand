#pragma once

#include <SDL_events.h>
#include <SDL_render.h>
#include <string>

class Player {
public:
    Player(int screenWidth, int screenHeight);
    void update(); 
    void jump(); 
    void bend();
    void render(SDL_Renderer* renderer);

    SDL_Rect getRect() const { return playerRect; }
    void setInput(bool jumpInput, bool bendInput);

private:
    int screenWidth, screenHeight;
    SDL_Rect playerRect;
    bool isJumping, isBending;
};
