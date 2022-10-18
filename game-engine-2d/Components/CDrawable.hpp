//
//  CDrawable.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-17.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CDrawable_hpp
#define CDrawable_hpp

#include <SFML/Graphics.hpp>
#include "Window.hpp"

class CDrawable {
public:
    CDrawable();
    virtual ~CDrawable();
    virtual void draw(Window& window) = 0;
    void setSortOrder(int order);
    int getSortOrder() const;
    
private:
    int sortOrder;
};

#endif /* CDrawable_hpp */
