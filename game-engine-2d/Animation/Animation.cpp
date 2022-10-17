//
//  Animation.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-14.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation(FacingDirection direction) : frames(0), currentFrameIndex(0), currentFrameTime(0.f), direction(direction) {}

void Animation::addFrame(int textureId, int x, int y, int width, int height, float frameTime) {
    FrameData data;
    data.id = textureId;
    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.displayTimeSeconds = frameTime;
    
    frames.push_back(data);
}

const FrameData* Animation::getCurrentFrame() const {
    if (frames.size() > 0) {
        return &frames[currentFrameIndex];
    }
    return nullptr;
}

bool Animation::updateFrame(float deltaTime) {
    if (frames.size() > 0) {
        currentFrameTime += deltaTime;
        if (currentFrameTime >= frames[currentFrameIndex].displayTimeSeconds) {
            currentFrameTime = 0.f;
            incrementFrame();
            return true;
        }
    }
    return false;
}

void Animation::incrementFrame() {
    currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}

void Animation::reset() {
    currentFrameIndex = 0;
    currentFrameTime = 0.f;
}

void Animation::setDirection(FacingDirection direction) {
    if(this->direction != direction) {
        this->direction = direction;
        for(auto& frame : frames) {
            frame.x += frame.width;
            frame.width *= -1;
        }
    }
}

FacingDirection Animation::getDirection() const {
    return direction;
}
