#include "Button.h"
#include <SDL_mouse.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <string>

Button::Button(int x, int y, int w, int h, const std::string& label, std::function<void()> action)
    : label(label), action(action) {
    buttonRect = { x, y, w, h };
}

void Button::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x > buttonRect.x && x < buttonRect.x + buttonRect.w &&
            y > buttonRect.y && y < buttonRect.y + buttonRect.h) {
            action();
        }
    }
}

void Button::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &buttonRect);
}
