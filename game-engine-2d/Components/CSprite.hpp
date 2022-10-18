//
//  CSprite.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CSprite_hpp
#define CSprite_hpp

#include "Component.hpp"
#include "CTransform.hpp"
#include "CDrawable.hpp"
#include "ResourceAllocator.hpp"

class CSprite : public Component, public CDrawable {
public:
    CSprite(Object* owner);
    //Loads a sprite from a file.
    void load(const std::string& filePath);
    void load(int id);
    void setTextureAllocator(ResourceAllocator<sf::Texture>* allocator);
    void setTextureRect(int x, int y, int width, int height);
    void setTextureRect(const sf::IntRect& rect);
    void setScale(float x, float y);
    //Override the draw method in order to draw the sprite
    void draw(Window& window) override;
    //Use this to update the sprite based on the position
    void lateUpdate(float deltaTime) override;
    
private:
    ResourceAllocator<sf::Texture>* allocator;
    int currentTextureId;
    sf::Sprite sprite;
};

#endif /* CSprite_hpp */
