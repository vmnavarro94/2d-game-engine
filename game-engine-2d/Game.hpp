//
//  Game.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "Window.hpp"

class Game
{
public:
    Game();
    void update();
    void lateUpdate();
    void draw();
    bool isRunning() const;
private:
    Window window;
};
#endif /* Game_hpp */
