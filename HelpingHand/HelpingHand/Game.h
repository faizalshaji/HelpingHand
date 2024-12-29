#pragma once

#include <vector>
#include "Player.h"
#include "Obstacle.h"
#include "Button.h"

class Game {
public:
    Game(const std::string& title, int width, int height);
    ~Game();

    void init();
    void run();
    bool isRunning() const;
    void handleEvents();
    void render();

    SDL_Renderer* getRenderer() const { return renderer; }

private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Player player;
    std::vector<Obstacle> obstacles;
    Button jumpButton;
    Button bendButton;
};
