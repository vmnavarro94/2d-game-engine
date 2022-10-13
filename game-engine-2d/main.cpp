//
//  main.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Game.hpp"
int main()
{
    Game game;
    while (game.isRunning())
    {
        game.captureInput();
        game.update();
        game.lateUpdate();
        game.draw();
        game.calculateDeltaTime();
    }
}
