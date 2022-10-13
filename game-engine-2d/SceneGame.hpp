//
//  SceneGame.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Scene.hpp"
#include "Input.hpp"
#include "WorkingDirectory.hpp"
#include "Object.hpp"
#include "CSprite.hpp"
#include "CKeyboardMovement.hpp"

class SceneGame : public Scene {
public:
    SceneGame(WorkingDirectory& workingDirectory);
    void onCreate() override;
    void onDestroy() override;
    void processInput() override;
    void update(float deltaTime) override;
    void lateUpdate(float deltaTime) override;
    void draw(Window& window) override;
    
private:
    std::shared_ptr<Object> player;
    WorkingDirectory& workingDirectory;
    Input input;
};

#endif /* SceneGame_hpp */
