//
//  CAnimation.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-14.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CAnimation.hpp"
#include "Object.hpp"

CAnimation::CAnimation(Object* owner)
    : Component(owner), currentAnimation(AnimationState::None, nullptr) {}

void CAnimation::awake() {
    sprite = owner->getComponent<CSprite>();
}

void CAnimation::update(float deltaTime) {
    if (currentAnimation.first != AnimationState::None) {
        bool newFrame = currentAnimation.second->updateFrame(deltaTime);
        
        if (newFrame) {
            const FrameData* data = currentAnimation.second->getCurrentFrame();
            sprite->load(data->id);
            sprite->setTextureRect(data->x, data->y,
                                               data->width, data->height);
        }
    }
}

void CAnimation::addAnimation(AnimationState state, std::shared_ptr<Animation> animation) {
    auto inserted = animations.insert(std::make_pair(state, animation));
    
    if (currentAnimation.first == AnimationState::None) {
        setAnimationState(state);
    }
}

void CAnimation::setAnimationState(AnimationState state) {
    //Only set an animation if it is not already the current one
    if (currentAnimation.first == state) {
        return;
    }
    
    auto animation = animations.find(state);
    if (animation != animations.end()) {
        currentAnimation.first = animation->first;
        currentAnimation.second = animation->second;
        
        currentAnimation.second->reset();
    }
}

const AnimationState& CAnimation::getAnimationState() const {
    //Returns the current animation state.
    //This can be use to compare the objects current state to a desired one
    return currentAnimation.first;
}

void CAnimation::setAnimationDirection(FacingDirection direction) {
    if(currentAnimation.first != AnimationState::None) {
        currentAnimation.second->setDirection(direction);
        currentAnimation.second->setDirection(direction);
    }
}
