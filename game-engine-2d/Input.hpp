//
//  Input.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "Bitmask.hpp"
#include <SFML/Graphics.hpp>

class Input {
public:
    enum class Key {
        None = 0,
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Esc = 5
    };
    void update();
    // Returns true if the key is pressed
    bool isKeyPressed(Key keycode);
    // Returns true if the key was just pressed
    bool isKeyDown(Key keycode);
    // Returns true if the key was just released
    bool isKeyUp(Key keycode);
    
private:
    Bitmask thisFrameKeys;
    Bitmask lastFrameKeys;
};

#endif /* Input_hpp */
