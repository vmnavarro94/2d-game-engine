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
                    Window& window)
: sceneStateMachine(sceneStateMachine),
    workingDirectory(workingDirectory),
    window(window),
    switchToState(0),
    currentSeconds(0.f),
    showForSeconds(3.f) {}

void SceneSplashScreen::onCreate() {
    //Initialise splash screen image here
    splashTexture.loadFromFile(workingDirectory.get() + "RhythmOfWar.jpg");
    splashSprite.setTexture(splashTexture);
    sf::FloatRect spriteSize = splashSprite.getLocalBounds();
    //Set the origin of the sprite to the centre of the image
    const float spriteScale = 0.15f;
    splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
    splashSprite.setScale(spriteScale, spriteScale);
    sf::Vector2u windowCentre = window.getCentre();
    //Positions sprite in centreof screen
    splashSprite.setPosition(windowCentre.x, windowCentre.y);
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
