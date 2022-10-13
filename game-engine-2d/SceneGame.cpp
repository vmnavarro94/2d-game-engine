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
    player = std::make_shared<Object>();
    
    // Adds a component by calling template function
    auto sprite = player->addComponent<CSprite>();
    sprite->load(workingDirectory.get() + "viking.png");
    
    auto movement = player->addComponent<CKeyboardMovement>();
    movement->setInput(&input);
}

void SceneGame::onDestroy() {}

void SceneGame::processInput() {
    input.update();
}

void SceneGame::update(float deltaTime) {
    player->update(deltaTime);
}

void SceneGame::lateUpdate(float deltaTime) {
    player->lateUpdate(deltaTime);
}

void SceneGame::draw(Window &window) {
    player->draw(window);
}
