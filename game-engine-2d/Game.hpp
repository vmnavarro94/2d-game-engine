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
#include "Input.hpp"
#include "WorkingDirectory.hpp"

class Game
{
public:
    Game();
    void update();
    void lateUpdate();
    void draw();
    bool isRunning() const;
    void calculateDeltaTime();
    void captureInput();
private:
    Window window;
    WorkingDirectory workingDirectory;
    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;
    sf::Clock clock;
    float deltaTime;
    Input input;
};
#endif /* Game_hpp */
