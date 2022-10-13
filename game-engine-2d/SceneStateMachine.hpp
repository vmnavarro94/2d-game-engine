//
//  SceneStateMachine.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef SceneStateMachine_hpp
#define SceneStateMachine_hpp

#include <memory>
#include <unordered_map>
#include "Scene.hpp"
#include "Window.hpp"

class SceneStateMachine {
public:
    SceneStateMachine();
    //Pass through methods. They will call the correspondingly named methods of the scene.
    void processInput();
    void update(float deltaTime);
    void lateUpdate(float deltaTime);
    void draw(Window& window);
    //Adds a scene to the state machine and returns the id of that scene.
    unsigned int add(std::shared_ptr<Scene> scene);
    //Transitions to scene with specified id.
    void switchTo(unsigned int id);
    //Removes scene from state machine.
    void remove(unsigned int id);
    
private:
    //Stores all of the scenes associated with this state machine.
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
    //Stores a reference to the current scene.
    //Used when drawing/updating.
    std::shared_ptr<Scene> currentScene;
    //Stores the current scene id.
    //This is incremented whenever a scene is added.
    unsigned int insertedSceneId;
};

#endif /* SceneStateMachine_hpp */
