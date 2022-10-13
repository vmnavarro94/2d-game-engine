//
//  SceneStateMachine.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine() : scenes(0), currentScene(0) {}

void SceneStateMachine::processInput() {
    if (currentScene) {
        currentScene->processInput();
    }
}

void SceneStateMachine::update(float deltaTime) {
    if (currentScene) {
        currentScene->update(deltaTime);
    }
}

void SceneStateMachine::lateUpdate(float deltaTime) {
    if (currentScene) {
        currentScene->lateUpdate(deltaTime);
    }
}

void SceneStateMachine::draw(Window &window) {
    if (currentScene) {
        currentScene->draw(window);
    }
}

unsigned int SceneStateMachine::add(std::shared_ptr<Scene> scene) {
    auto inserted = scenes.insert(std::make_pair(insertedSceneId, scene));
    insertedSceneId++;
    inserted.first->second->onCreate();
    return insertedSceneId - 1;
}

void SceneStateMachine::remove(unsigned int id) {
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (currentScene == it->second) {
            //If the scene being removed is the current scene
            //it is necessary to set that to a null pointer
            //so the scene is no longer updated
            currentScene = nullptr;
        }
        //Making sure to call the onDestroy method of the scene that is being removed
        it->second->onDestroy();
        scenes.erase(it);
    }
}

void SceneStateMachine::switchTo(unsigned int id) {
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (currentScene) {
            //If a current scene exist, call it's onDeactivate method
            currentScene->onDeactivate();
        }
        //Setting the current scene ensures that it is updated and draw
        currentScene = it->second;
        currentScene->onActivate();
    }
}
