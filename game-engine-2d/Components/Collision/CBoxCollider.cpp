//
//  CBoxCollider.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 23/10/22.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CBoxCollider.hpp"
#include "Object.hpp"

CBoxCollider::CBoxCollider(Object* owner) : CCollider(owner), offset(sf::Vector2f(0.f, 0.f)) {}

void CBoxCollider::setCollidable(const sf::FloatRect &rect) {
    AABB = rect;
    setPosition();
}

const sf::FloatRect& CBoxCollider::getCollidable() {
    setPosition();
    return AABB;
}

void CBoxCollider::setPosition() {
    const sf::Vector2f& pos = owner->transform->getPosition();
    AABB.left = pos.x - (AABB.width / 2) + offset.x;
    AABB.top = pos.y - (AABB.height / 2) + offset.y;
}

Manifold CBoxCollider::intersects(std::shared_ptr<CCollider> other) {
    Manifold manifold;
    manifold.colliding = false;
    std::shared_ptr<CBoxCollider> boxCollider = std::dynamic_pointer_cast<CBoxCollider>(other);
    
    if (boxCollider) {
        const sf::FloatRect& rect1 = getCollidable();
        const sf::FloatRect& rect2 = boxCollider->getCollidable();
        
        if (rect1.intersects(rect2)) {
            manifold.colliding = true;
            manifold.other = &rect2;
        }
    }
    return manifold;
}

void CBoxCollider::resolveOverlap(const Manifold& manifold) {
    auto transform = owner->transform;
    
    if (transform->isStatic()) {
        return;
    }
    
    const sf::FloatRect& rect1 = getCollidable();
    const sf::FloatRect* rect2 = manifold.other;
    float resolve = 0.f;
    float xDiff = (rect1.left + (rect1.width * 0.5f)) - (rect2->left + (rect2->width * 0.5f));
    float yDiff = (rect1.top + (rect1.height * 0.5f)) - (rect2->top + (rect2->height * 0.5f));

    if (fabs(xDiff) > fabs(yDiff)) {
        if (xDiff > 0) {
            resolve = (rect2->left + rect2->width) - rect1.left;
        } else {
            resolve = - ((rect1.left + rect1.width) - rect2->left);
        }
        transform->addPosition(resolve, 0);
    } else {
        if (yDiff > 0) {
            resolve = (rect2->top + rect2->height) - rect1.top;
        } else {
            resolve = - ((rect1.top + rect1.height) - rect2->top);
        }
        transform->addPosition(0, resolve);
    }
}

void CBoxCollider::setOffset(const sf::Vector2f &offset) {
    this->offset = offset;
}

void CBoxCollider::setOffset(float x, float y) {
    offset.x = x;
    offset.y = y;
}

void CBoxCollider::setSize(const sf::Vector2f &size) {
    AABB.width = size.x;
    AABB.height = size.y;
}

void CBoxCollider::setSize(float width, float height) {
    AABB.width = width;
    AABB.height = height;
}
