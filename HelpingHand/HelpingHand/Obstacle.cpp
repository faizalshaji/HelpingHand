#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, ObstacleType type)
    : type(type) {
    obstacleRect = { x, y, 100, 50 }; 
}

void Obstacle::update() {
    obstacleRect.x -= 0.0000000000005; 
    if (obstacleRect.x < -100) {
        obstacleRect.x = 800;
    }
}

void Obstacle::render(SDL_Renderer* renderer) {
    if (type == ObstacleType::LOG) {
        SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
    }
    else if (type == ObstacleType::BANNER) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }

    SDL_RenderFillRect(renderer, &obstacleRect);
}
