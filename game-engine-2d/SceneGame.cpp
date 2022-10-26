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
    : workingDirectory(workingDirectory), textureAllocator(textureAllocator), mapParser(textureAllocator) {}

void SceneGame::onCreate() {
    /*
    for (int i = 0; i < 500; i++)
    {
        std::shared_ptr<Object> player = std::make_shared<Object>();
        
        auto sprite = player->addComponent<CSprite>();
        sprite->setTextureAllocator(&textureAllocator);
        
        auto animation = player->addComponent<CAnimation>();
        
        int vikingTextureID = textureAllocator.add(workingDirectory.get() + "viking.png");
        
        const int frameWidth = 165;
        const int frameHeight = 145;
        
        std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);
        const float idleAnimFrameSeconds = 0.2f;
        idleAnimation->addFrame(vikingTextureID, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
        idleAnimation->addFrame(vikingTextureID, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
        idleAnimation->addFrame(vikingTextureID, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
        idleAnimation->addFrame(vikingTextureID, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
        animation->addAnimation(AnimationState::Idle, idleAnimation);
        
        float x = static_cast <float> (rand()) /(static_cast <float> (RAND_MAX/(1920-0)));
        float y = static_cast <float> (rand()) /(static_cast <float> (RAND_MAX/(1080-0)));
        
        player->transform->setPosition(x, y);
        
        auto collider = player->addComponent<CBoxCollider>();
        collider->setCollidable(sf::FloatRect(x, y, frameWidth, frameHeight));
        collider->setLayer(CollisionLayer::Default);
        
        objects.add(player);
    }
    */
    
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
    
    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float idleAnimFrameSeconds = 0.2f;
    idleAnimation->addFrame(vikingTextureId, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(vikingTextureId, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(vikingTextureId, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(vikingTextureId, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    animation->addAnimation(AnimationState::Idle, idleAnimation);
    
    std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float walkAnimFrameSeconds = 0.15f;
    walkAnimation->addFrame(vikingTextureId, 600, 290, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->addFrame(vikingTextureId, 800, 290, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->addFrame(vikingTextureId, 0, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->addFrame(vikingTextureId, 200, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->addFrame(vikingTextureId, 400, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    animation->addAnimation(AnimationState::Walk, walkAnimation);
    
    player->transform->setPosition(100, 700);
    auto collider = player->addComponent<CBoxCollider>();
    collider->setSize(frameWidth * 0.4f, frameHeight * 0.5f);
    collider->setOffset(0.f, 14.f);
    collider->setLayer(CollisionLayer::Player);
    objects.add(player);
    
    sf::Vector2i mapOffset(-100,180);
    const std::string workingDir = workingDirectory.get();
    std::vector<std::shared_ptr<Object>> levelTiles = mapParser.parse(workingDirectory.get() + "TestMap1.tmx", mapOffset);
    
    objects.add(levelTiles);
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
    Debug::draw(window);
}
