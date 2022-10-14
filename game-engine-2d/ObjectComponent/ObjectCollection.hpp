//
//  ObjectCollection.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef ObjectCollection_hpp
#define ObjectCollection_hpp

#include <memory>
#include <vector>
#include "Object.hpp"

class ObjectCollection {
public:
    void add(std::shared_ptr<Object> object);
    void update(float deltaTime);
    void lateUpdate(float deltaTime);
    void draw(Window& window);
    void processNewObjects();
    void processRemovals();
    
private:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Object>> newObjects;
};

#endif /* ObjectCollection_hpp */
