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

void CSprite::setTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
    this->allocator = allocator;
}

void CSprite::load(int id)
{
    if(id >= 0)
    {
        std::shared_ptr<sf::Texture> texture = allocator->get(id);
        sprite.setTexture(*texture);
    }
}


void CSprite::load(const std::string &filePath) {
    if (allocator) {
        int textureId = allocator->add(filePath);
        if (textureId >= 0) {
            std::shared_ptr<sf::Texture> texture = allocator->get(textureId);
            sprite.setTexture(*texture);
        }
    }
}

void CSprite::draw(Window &window) {
    window.draw(sprite);
}

void CSprite::lateUpdate(float deltaTime) {
    sprite.setPosition(owner->transform->getPosition());
}
