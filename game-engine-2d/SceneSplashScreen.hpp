//
//  SceneSplashScreen.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp

#include <SFML/Graphics.hpp>
#include "SceneStateMachine.hpp"
#include "WorkingDirectory.hpp"
#include "ResourceAllocator.hpp"

class SceneSplashScreen : public Scene {
public:
    SceneSplashScreen(WorkingDirectory& workingDirectory,
                      SceneStateMachine& sceneStateMachine,
                      Window& window,
                      ResourceAllocator<sf::Texture>& textureAllocator);
    void onCreate() override;
    void onDestroy() override;
    void onActivate() override;
    void update(float deltaTime) override;
    void draw(Window& window) override;
    void setSwitchToScene(unsigned int id);
    
private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;
    WorkingDirectory& workingDirectory;
    SceneStateMachine& sceneStateMachine;
    ResourceAllocator<sf::Texture>& textureAllocator;
    Window& window;
    //This scene will be shown for a set amount of time
    float showForSeconds;
    //How long the scene has currently been visible
    float currentSeconds;
    //The state we want to transition to when this scenes time expires
    unsigned int switchToState;
};

#endif /* SceneSplashScreen_hpp */
