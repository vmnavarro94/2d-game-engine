//
//  Game.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "Window.hpp"
#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneGame.hpp"
#include "ResourceAllocator.hpp"

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
    ResourceAllocator<sf::Texture> textureAllocator;

    sf::Clock clock;
    float deltaTime;
    SceneStateMachine sceneStateMachine;
};
#endif /* Game_hpp */
