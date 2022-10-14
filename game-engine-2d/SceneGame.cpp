//
//  SceneGame.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDirectory,
                     ResourceAllocator<sf::Texture>& textureAllocator)
: workingDirectory(workingDirectory), textureAllocator(textureAllocator) {}

void SceneGame::onCreate() {
    std::shared_ptr<Object> player = std::make_shared<Object>();
    auto sprite = player->addComponent<CSprite>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load(workingDirectory.get() + "viking.png");
    
    auto movement = player->addComponent<CKeyboardMovement>();
    movement->setInput(&input);
    
    objects.add(player);
}

void SceneGame::onDestroy() {}

void SceneGame::processInput() {
    input.update();
}

void SceneGame::update(float deltaTime) {
    objects.processRemovals();
    objects.processNewObjects();
    objects.update(deltaTime);
}

void SceneGame::lateUpdate(float deltaTime) {
    objects.lateUpdate(deltaTime);
}

void SceneGame::draw(Window &window) {
    objects.draw(window);
}
