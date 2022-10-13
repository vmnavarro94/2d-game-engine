//
//  Component.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include "Window.hpp"

class Object;

class Component {
public:
    Component(Object* owner) : owner(owner) {}
    virtual void awake() {};
    virtual void start() {};
    virtual void update(float deltaTime) {};
    virtual void lateUpdate(float deltaTime) {};
    virtual void draw(Window& window) {};
    
protected:
    Object* owner;
};

#endif /* Component_hpp */
