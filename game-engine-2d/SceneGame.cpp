//
//  SceneGame.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDirectory)
: workingDirectory(workingDirectory) {}

void SceneGame::onCreate() {
    vikingTexture.loadFromFile(workingDirectory.get() + "viking.png");
    vikingSprite.setTexture(vikingTexture);
}

void SceneGame::onDestroy() {}

void SceneGame::processInput() {
    input.update();
}

void SceneGame::update(float deltaTime) {
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

void SceneGame::draw(Window &window) {
    window.draw(vikingSprite);
}
