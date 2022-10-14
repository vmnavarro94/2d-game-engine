//
//  Game.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Game.hpp"

Game::Game(): window("2D Game Engine") {
    std::shared_ptr<SceneSplashScreen> splashScreen = std::make_shared<SceneSplashScreen>(workingDirectory, sceneStateMachine, window, textureAllocator);
    std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(workingDirectory, textureAllocator);
    
    unsigned int splashScreenID = sceneStateMachine.add(splashScreen);
    unsigned int gameSceneID = sceneStateMachine.add(gameScene);
    
    splashScreen->setSwitchToScene(gameSceneID);
    sceneStateMachine.switchTo(splashScreenID);
    deltaTime = clock.restart().asSeconds();
}

void Game::update()
{
    window.update();
    sceneStateMachine.update(deltaTime);
}

void Game::lateUpdate() {
    sceneStateMachine.lateUpdate(deltaTime);
}


void Game::draw()
{
    window.beginDraw();
    sceneStateMachine.draw(window);
    window.endDraw();
}


bool Game::isRunning() const
{
    return window.isOpen();
}

void Game::calculateDeltaTime() {
    deltaTime = clock.restart().asSeconds();
}

void Game::captureInput() {
    sceneStateMachine.processInput();
}
