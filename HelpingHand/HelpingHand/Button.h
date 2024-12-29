#pragma once

#include <functional>
#include <SDL_events.h>
#include <SDL_render.h>
#include <string>

class Button {
public:
    Button(int x, int y, int w, int h, const std::string& label, std::function<void()> action);
    void handleEvent(const SDL_Event& event); // Handle button click
    void render(SDL_Renderer* renderer); // Render the button

private:
    SDL_Rect buttonRect;
    std::string label;
    std::function<void()> action;
};
