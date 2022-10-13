//
//  Game.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Game.hpp"
Game::Game(): window("2D Game Engine") {}
void Game::update()
{
    window.update();
}
void Game::draw()
{
    window.beginDraw();
    // We’ll add draw code here.
    window.endDraw();
}
void Game::lateUpdate() { }
bool Game::isRunning() const
{
    return window.isOpen();
}
