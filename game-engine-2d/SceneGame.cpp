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
    
    auto movement = player->addComponent<CKeyboardMovement>();
    movement->setInput(&input);
    
    auto animation = player->addComponent<CAnimation>();
    
    int vikingTextureId = textureAllocator.add(workingDirectory.get() + "viking.png");
    
    //TODO: Generate some form of data file to do this automatically
    const int frameWidth = 165;
    const int frameHeight = 145;
    //ENDTODO
    
    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>();
    const float idleAnimFrameSeconds = 0.2f;
    idleAnimation->addFrame(vikingTextureId, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(vikingTextureId, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(vikingTextureId, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(vikingTextureId, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    animation->addAnimation(AnimationState::Idle, idleAnimation);
    
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
