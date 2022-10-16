//
//  Animation.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-14.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include <vector>

struct FrameData
{
    int id;                     // Texture id (retrieved from texture allocator).
    int x;                      // x position of sprite in the texture.
    int y;                      // y position of sprite in the texture.
    int width;                  // Width of sprite.
    int height;                 // Height of sprite.
    float displayTimeSeconds;   // How long to display the frame.
};

class Animation {
public:
    Animation();
    void addFrame(int textureId,
                  int x, int y,
                  int width, int height,
                  float frameTime);
    const FrameData* getCurrentFrame() const;
    bool updateFrame(float deltaTime);
    void reset();
    
private:
    void incrementFrame();
    //Stores all frames for the animation
    std::vector<FrameData> frames;
    //Current frame
    int currentFrameIndex;
    //This is used to decide when to transition to the next frame
    float currentFrameTime;
};

#endif /* Animation_hpp */
