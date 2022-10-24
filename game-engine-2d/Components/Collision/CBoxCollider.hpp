//
//  CBoxCollider.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 23/10/22.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CBoxCollider_hpp
#define CBoxCollider_hpp

#include "Component.hpp"
#include "CCollider.hpp"
#include <math.h>

class CBoxCollider : public CCollider {
public:
    CBoxCollider(Object* owner);
    Manifold intersects(std::shared_ptr<CCollider> other) override;
    void resolveOverlap(const Manifold& maniforld) override;
    void setCollidable(const sf::FloatRect& rect);
    const sf::FloatRect& getCollidable();
    
private:
    void setPosition();
    sf::FloatRect AABB;
    sf::Vector2f offset;
};

#endif /* CBoxCollider_hpp */
