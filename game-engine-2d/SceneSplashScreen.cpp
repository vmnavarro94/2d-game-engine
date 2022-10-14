//
//  SceneSplashScreen.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(
                    WorkingDirectory& workingDirectory,
                    SceneStateMachine& sceneStateMachine,
                    Window& window,
                    ResourceAllocator<sf::Texture>& textureAllocator)
: sceneStateMachine(sceneStateMachine),
    workingDirectory(workingDirectory),
    window(window),
    switchToState(0),
    currentSeconds(0.f),
    showForSeconds(3.f),
    textureAllocator(textureAllocator){}

void SceneSplashScreen::onCreate() {
    int textureId = textureAllocator.add(workingDirectory.get() + "RhythmOfWar.jpg");
    
    if(textureId >= 0)
    {
        std::shared_ptr<sf::Texture> texture = textureAllocator.get(textureId);
        splashSprite.setTexture(*texture);
        
        sf::FloatRect spriteSize = splashSprite.getLocalBounds();
        splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
        splashSprite.setScale(0.5f, 0.5f);
        
        sf::Vector2u windowCentre = window.getCentre();
        splashSprite.setPosition(windowCentre.x, windowCentre.y);
    }
}

void SceneSplashScreen::onActivate() {
    //Resets the currentSeconds count whenever the scene is activated
    currentSeconds = 0.f;
}

void SceneSplashScreen::onDestroy() {}

void SceneSplashScreen::setSwitchToScene(unsigned int id) {
    //Stores the id of the scene that we will transition to
    switchToState = id;
}

void SceneSplashScreen::update(float deltaTime) {
    currentSeconds += deltaTime;
    if (currentSeconds >= showForSeconds) {
        //Switches states
        sceneStateMachine.switchTo(switchToState);
    }
}

void SceneSplashScreen::draw(Window &window) {
    window.draw(splashSprite);
}
