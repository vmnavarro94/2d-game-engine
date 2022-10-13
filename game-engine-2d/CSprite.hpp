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

class CSprite : public Component {
public:
    CSprite(Object* owner);
    //Loads a sprite from a file.
    void load(const std::string& filePath);
    //Override the draw method in order to draw the sprite
    void draw(Window& window) override;
    
private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif /* CSprite_hpp */
