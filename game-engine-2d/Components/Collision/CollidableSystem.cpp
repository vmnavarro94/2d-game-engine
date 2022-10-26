//
//  CollidableSystem.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-26.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CollidableSystem.hpp"

CollidableSystem::CollidableSystem() {
    Bitmask defaultCollisions;
    defaultCollisions.setBit((int)CollisionLayer::Default);
    collisionLayers.insert(std::make_pair(CollisionLayer::Default, defaultCollisions));
    collisionLayers.insert(std::make_pair(CollisionLayer::Tile, Bitmask(0)));
    
    Bitmask playerCollisions;
    playerCollisions.setBit((int) CollisionLayer::Default);
    playerCollisions.setBit((int) CollisionLayer::Tile);
    collisionLayers.insert(std::make_pair(CollisionLayer::Player, playerCollisions));
}

void CollidableSystem::add(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto object : objects) {
        auto collider = object->getComponent<CBoxCollider>();
        if (collider) {
            CollisionLayer layer = collider->getLayer();
            auto itr = collidables.find(layer);
            if (itr != collidables.end()) {
                collidables[layer].push_back(collider);
            } else {
                std::vector<std::shared_ptr<CBoxCollider>> objs;
                objs.push_back(collider);
                collidables.insert(std::make_pair(layer, objs));
            }
        }
    }
}

void CollidableSystem::processRemovals() {
    for (auto& layer : collidables) {
        auto itr = layer.second.begin();
        while (itr != layer.second.end()) {
            if ((*itr)->owner->isQueuedForRemoval()) {
                itr = layer.second.erase(itr);
            } else {
                itr++;
            }
        }
    }
}

void CollidableSystem::update() {
    collisionTree.clear();
    for (auto maps = collidables.begin(); maps != collidables.end(); maps++) {
        for (auto collidable : maps->second) {
            collisionTree.insert(collidable);
        }
    }
    resolve();
}

void CollidableSystem::resolve() {
    for (auto maps = collidables.begin(); maps != collidables.end(); maps++) {
        // If this layer collides with nothing then no need to perform more checks
        if (collisionLayers[maps->first].getMask() == 0) {
            continue;
        }
        for (auto collidable : maps->second) {
            //if this collidable is static
            //then no need to check if it is colliding with other objects
            if (collidable->owner->transform->isStatic()) {
                continue;
            }
            std::vector<std::shared_ptr<CBoxCollider>> collisions = collisionTree.search(collidable->getCollidable());
            for (auto collision : collisions) {
                //make sure to not resolve collisions between the same object
                if (collidable->owner->instanceId->get() ==
                    collision->owner->instanceId->get()) {
                    continue;
                }
                bool layersCollide =
                    collisionLayers[collidable->getLayer()].getBit(((int)collision->getLayer()));
                if (layersCollide) {
                    Manifold manifold = collidable->intersects(collision);
                    if (manifold.colliding) {
                        if (collision->owner->transform->isStatic()) {
                            collidable->resolveOverlap(manifold);
                        } else {
                            //TODO: Handle collisions when both objects are not static
                            collidable->resolveOverlap(manifold);
                        }
                    }
                }
            }
        }
    }
}
