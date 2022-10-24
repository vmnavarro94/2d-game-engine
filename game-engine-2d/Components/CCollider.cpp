//
//  CCollider.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 23/10/22.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CCollider.hpp"

CCollider::CCollider(Object* owner) : Component(owner), layer(CollisionLayer::Default) {}

CCollider::~CCollider() {}

CollisionLayer CCollider::getLayer() const {
    return layer;
}

void CCollider::setLayer(CollisionLayer layer) {
    this->layer = layer;
}
