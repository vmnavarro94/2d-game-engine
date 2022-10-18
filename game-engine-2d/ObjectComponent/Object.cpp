//
//  Object.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Object.hpp"

Object::Object() : queuedForRemoval(false) {
    transform = addComponent<CTransform>();
}

void Object::awake() {
    for(int i = components.size() - 1; i >= 0; i--) {
        components[i]->awake();
    }
}

void Object::start() {
    for(int i = components.size() - 1; i >= 0; i--) {
        components[i]->start();
    }
}

void Object::update(float deltaTime) {
    for(int i = components.size() - 1; i >= 0; i--) {
        components[i]->update(deltaTime);
    }
}

void Object::lateUpdate(float deltaTime) {
    for(int i = components.size() - 1; i >= 0; i--) {
        components[i]->lateUpdate(deltaTime);
    }
}

void Object::draw(Window &window) {
    drawable->draw(window);
}

void Object::queueForRemoval() {
    queuedForRemoval = false;
}

bool Object::isQueuedForRemoval() {
    return queuedForRemoval;
}

std::shared_ptr<CDrawable> Object::getDrawable() {
    return drawable;
}
