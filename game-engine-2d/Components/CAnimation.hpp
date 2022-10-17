//
//  CAnimation.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-14.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CAnimation_hpp
#define CAnimation_hpp

#include "Component.hpp"
#include "Animation.hpp"
#include "CSprite.hpp"

enum class AnimationState {
    None,
    Idle,
    Walk
};

class CAnimation : public Component {
public:
    CAnimation(Object* owner);
    void awake() override;
    void update(float deltaTime) override;
    //Add animation to object.
    void addAnimation(AnimationState state, std::shared_ptr<Animation> animation);
    //Set current animation states
    void setAnimationState(AnimationState state);
    //Returns current animation state
    const AnimationState& getAnimationState() const;
    void setAnimationDirection(FacingDirection direction);
    
private:
    std::shared_ptr<CSprite> sprite;
    std::map<AnimationState, std::shared_ptr<Animation>> animations;
    //Reference to the current animation
    std::pair<AnimationState, std::shared_ptr<Animation>> currentAnimation;
};

#endif /* CAnimation_hpp */
