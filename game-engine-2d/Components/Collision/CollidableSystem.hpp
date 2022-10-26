//
//  CollidableSystem.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-26.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CollidableSystem_hpp
#define CollidableSystem_hpp

#include <vector>
#include <memory>
#include <set>
#include "Object.hpp"
#include "Quadtree.hpp"
#include "Bitmask.hpp"

class CollidableSystem {
public:
    CollidableSystem();
    void add(std::vector<std::shared_ptr<Object>>& objects);
    void processRemovals();
    void update();
    
private:
    void resolve();
    void processCollisions(std::vector<std::shared_ptr<Object>>& first,
                           std::vector<std::shared_ptr<Object>>& second);
    //This is used to store collision layer data (which layers can collide)
    std::map<CollisionLayer, Bitmask> collisionLayers;
    //The collision system stores all collidables along with their layer
    std::map<CollisionLayer, std::vector<std::shared_ptr<CBoxCollider>>> collidables;
    //The quadtree stores the collidables in a spatial aware structure
    Quadtree collisionTree;
};

#endif /* CollidableSystem_hpp */
