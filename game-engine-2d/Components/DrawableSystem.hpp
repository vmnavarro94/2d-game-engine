//
//  DrawableSystem.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-17.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef DrawableSystem_hpp
#define DrawableSystem_hpp

#include "CDrawable.hpp"
#include "Object.hpp"
#include <map>

class DrawableSystem {
public:
    void add(std::vector<std::shared_ptr<Object>>& object);
    void processRemovals();
    void draw(Window& window);
    
private:
    void add(std::shared_ptr<Object> object);
    void sort();
    std::vector<std::shared_ptr<Object>> drawables;
};

#endif /* DrawableSystem_hpp */
