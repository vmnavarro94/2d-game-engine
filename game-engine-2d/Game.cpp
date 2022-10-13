//
//  Game.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Game.hpp"

Game::Game(): window("2D Game Engine") {
    vikingTexture.loadFromFile(workingDirectory.get() + "viking.png");
    vikingSprite.setTexture(vikingTexture);
    deltaTime = clock.restart().asSeconds();
}

void Game::update()
{
    window.update();
    const sf::Vector2f &spritePos = vikingSprite.getPosition();
    const int moveSpeed = 100;
    int xMove = 0, yMove = 0;
    
    if (input.isKeyPressed(Input::Key::Left)) {
        xMove = -moveSpeed;
    } else if (input.isKeyPressed(Input::Key::Right)) {
        xMove = moveSpeed;
    }
    
    if (input.isKeyPressed(Input::Key::Up)) {
        yMove = -moveSpeed;
    } else if (input.isKeyPressed(Input::Key::Down)) {
        yMove = moveSpeed;
    }
    
    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    
    vikingSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
}

void Game::draw()
{
    window.beginDraw();
    window.draw(vikingSprite);
    // We’ll add draw code here.
    window.endDraw();
}

void Game::lateUpdate() { }

bool Game::isRunning() const
{
    return window.isOpen();
}

void Game::calculateDeltaTime() {
    deltaTime = clock.restart().asSeconds();
}

void Game::captureInput() {
    input.update();
}
