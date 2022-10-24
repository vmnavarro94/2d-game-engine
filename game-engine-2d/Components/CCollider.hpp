//
//  CCollider.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 23/10/22.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CCollider_hpp
#define CCollider_hpp

#include <memory>
#include <SFML/Graphics.hpp>
#include "Component.hpp"

enum class CollisionLayer {
    Default = 1,
    Player = 2,
    Tile = 3
};

struct Manifold {
    bool colliding = false;
    const sf::FloatRect* other;
};

class CCollider : public Component {
public:
    CCollider(Object* owner);
    ~CCollider();
    virtual Manifold intersects(std::shared_ptr<CCollider> other) = 0;
    virtual void resolveOverlap(const Manifold& manifold) = 0;
    CollisionLayer getLayer() const;
    void setLayer(CollisionLayer layer);
    
private:
    CollisionLayer layer;
};

#endif /* CCollider_hpp */
