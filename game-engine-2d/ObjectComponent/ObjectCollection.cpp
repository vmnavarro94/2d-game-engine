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
    collidables.update();
}

void ObjectCollection::lateUpdate(float deltaTime) {
    for(auto& object : objects) {
        object->lateUpdate(deltaTime);
    }
}

void ObjectCollection::draw(Window &window) {
    drawables.draw(window);
}

void ObjectCollection::add(std::shared_ptr<Object> object) {
    newObjects.push_back(object);
}

void ObjectCollection::add(std::vector<std::shared_ptr<Object>>& otherObjects) {
    newObjects.insert(newObjects.end(), otherObjects.begin(), otherObjects.end());
}

void ObjectCollection::processNewObjects() {
    if (newObjects.size() > 0) {
        for(auto& object : newObjects) {
            object->awake();
        }
        for(auto& object : newObjects) {
            object->start();
        }
        objects.insert(objects.end(), newObjects.begin(), newObjects.end());
        drawables.add(newObjects);
        collidables.add(newObjects);
        newObjects.clear();
    }
}

void ObjectCollection::processRemovals() {
    bool removed = false;
    auto objIterator = objects.begin();
    
    while (objIterator != objects.end()) {
        auto obj = *objIterator;
        if (obj->isQueuedForRemoval()) {
            objIterator = objects.erase(objIterator);
            removed = true;
        } else {
            objIterator++;
        }
    }
    
    if(removed) {
        drawables.processRemovals();
        collidables.processRemovals();
    }
}
