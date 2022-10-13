//
//  CSprite.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CSprite.hpp"
#include "Object.hpp"

CSprite::CSprite(Object* owner) : Component(owner) {}

void CSprite::load(const std::string &filePath) {
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void CSprite::draw(Window &window) {
    window.draw(sprite);
}

void CSprite::lateUpdate(float deltaTime) {
    sprite.setPosition(owner->transform->getPosition());
}
