//
//  Scene.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include "Window.hpp"

class Scene {
public:
    //Called when scene initially created. This is called once.
    virtual void onCreate() = 0;
    //Called when scene is destroyed. Called at most once.
    //(if a scene is not removed from the game, this will never be called).
    virtual void onDestroy() = 0;
    //Called whenever a scene is transitioned into.
    //This can be called several times in a typical game cycle.
    virtual void onActivate() {};
    //Called whenever a transition out of a scene occurs.
    //This can be called several times in a typical game cycle.
    virtual void onDeactivate() {};
    
    //Below functions can be overridden as necessary in the scenes.
    virtual void processInput() {};
    virtual void update(float deltaTime) {};
    virtual void lateUpdate(float deltaTime) {};
    virtual void draw(Window& window) {};
};


#endif /* Scene_hpp */
