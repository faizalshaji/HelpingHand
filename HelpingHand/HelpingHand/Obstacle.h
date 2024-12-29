#pragma once

#include <SDL_events.h>
#include <SDL_render.h>
#include <string>


enum class ObstacleType {
    LOG,
    BANNER
};

class Obstacle {
public:
    Obstacle(int x, int y, ObstacleType type);
    void update(); 
    void render(SDL_Renderer* renderer);

    SDL_Rect getRect() const { return obstacleRect; }
    ObstacleType getType() const { return type; }

private:
    SDL_Rect obstacleRect;
    ObstacleType type;
};
