#include "Game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

Game::Game(const std::string& title, int width, int height)
    : running(true), player(width, height), jumpButton(50, 550, 100, 50, "Jump", [&]() { player.jump(); }),
    bendButton(650, 550, 100, 50, "Bend", [&]() { player.bend(); }) {

    obstacles.push_back(Obstacle(600, 300, ObstacleType::LOG));
    obstacles.push_back(Obstacle(1200, 250, ObstacleType::BANNER));
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::init() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    window = SDL_CreateWindow("Running Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Game::run() {
    while (isRunning()) {
        handleEvents();
        player.update();

        for (auto& obstacle : obstacles) {
            obstacle.update();
        }

        render();
    }
}

bool Game::isRunning() const {
    return running;
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        jumpButton.handleEvent(event);
        bendButton.handleEvent(event);
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    player.render(renderer);

    for (auto& obstacle : obstacles) {
        obstacle.render(renderer);
    }

    jumpButton.render(renderer);
    bendButton.render(renderer);

    SDL_RenderPresent(renderer);
}
