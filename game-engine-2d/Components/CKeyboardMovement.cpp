//
//  CKeyboardMovement.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CKeyboardMovement.hpp"
#include "Object.hpp"

CKeyboardMovement::CKeyboardMovement(Object* owner)
    : Component(owner), moveSpeed(200) {}

void CKeyboardMovement::setInput(Input *input) {
    this->input = input;
}

void CKeyboardMovement::setMovementSpeed(int moveSpeed) {
    this->moveSpeed = moveSpeed;
}

void CKeyboardMovement::update(float deltaTime) {
    if (input == nullptr) {
        return;
    }
    int xMove = 0, yMove = 0;
    
    if (input->isKeyPressed(Input::Key::Left)) {
        xMove = -moveSpeed;
        animation->setAnimationDirection(FacingDirection::Left);
    }
    if (input->isKeyPressed(Input::Key::Right)) {
        xMove = moveSpeed;
        animation->setAnimationDirection(FacingDirection::Right);
    }
    if (input->isKeyPressed(Input::Key::Up)) {
        yMove = -moveSpeed;
    }
    if (input->isKeyPressed(Input::Key::Down)) {
        yMove = moveSpeed;
    }
    
    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    owner->transform->addPosition(xFrameMove, yFrameMove);
    
    if(xMove == 0 && yMove == 0) {
        animation->setAnimationState(AnimationState::Idle);
    } else {
        animation->setAnimationState(AnimationState::Walk);
    }
}

void CKeyboardMovement::awake() {
    animation = owner->getComponent<CAnimation>();
}
