//
//  CKeyboardMovement.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CKeyboardMovement_hpp
#define CKeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"
#include "CAnimation.hpp"

class CKeyboardMovement : public Component {
public:
    CKeyboardMovement(Object *owner);
    void setInput(Input* input);
    void setMovementSpeed(int moveSpeed);
    void update(float deltaTime) override;
    void awake() override;
    
private:
    int moveSpeed;
    Input* input;
    std::shared_ptr<CAnimation> animation;
};

#endif /* CKeyboardMovement_hpp */
