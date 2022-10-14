//
//  ObjectCollection.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "ObjectCollection.hpp"

void ObjectCollection::update(float deltaTime) {
    for(auto& object : objects) {
        object->update(deltaTime);
    }
}

void ObjectCollection::lateUpdate(float deltaTime) {
    for(auto& object : objects) {
        object->lateUpdate(deltaTime);
    }
}

void ObjectCollection::draw(Window &window) {
    for(auto& object : objects) {
        object->draw(window);
    }
}

void ObjectCollection::add(std::shared_ptr<Object> object) {
    newObjects.push_back(object);
}

void ObjectCollection::processNewObjects() {
    if (newObjects.size() > 0) {
        for(auto& object : objects) {
            object->awake();
        }
        for(auto& object : objects) {
            object->start();
        }
        objects.assign(newObjects.begin(), newObjects.end());
        newObjects.clear();
    }
}

void ObjectCollection::processRemovals() {
    auto objIterator = objects.begin();
    while(objIterator != objects.end()) {
        auto obj = **objIterator;
        if (obj.isQueuedForRemoval()) {
            objIterator = objects.erase(objIterator);
        }
        else {
            objIterator++;
        }
    }
}
