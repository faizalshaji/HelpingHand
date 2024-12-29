#include "Player.h"

Player::Player(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight), isJumping(false), isBending(false) {
    playerRect = { 100, screenHeight / 2 - 25, 50, 50 };
}

void Player::update() {
    playerRect.x += 0.000002;
    if (playerRect.x > screenWidth) {
        playerRect.x = -50;
    }
}

void Player::jump() {
    if (!isJumping) {
        playerRect.y -= 50;
        isJumping = true;
    }
}

void Player::bend() {
    if (!isBending) {
        playerRect.h = 25;
        isBending = true;
    }
}

void Player::setInput(bool jumpInput, bool bendInput) {
    if (jumpInput) {
        jump();
    }
    if (bendInput) {
        bend();
    }
}

void Player::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &playerRect);
}
