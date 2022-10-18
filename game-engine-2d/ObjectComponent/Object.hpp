//
//  Object.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include "Window.hpp"
#include "Component.hpp"
#include "CTransform.hpp"
#include "CDrawable.hpp"
#include <vector>

class Object {
public:
    Object();
    //Awake is called when object created
    //Use to ensure required components are present.
    void awake();
    //Start is called after awake method.
    //Use to initialise variables
    void start();
    void update(float deltaTime);
    void lateUpdate(float deltaTime);
    void draw(Window& window);
    std::shared_ptr<CTransform> transform;
    bool isQueuedForRemoval();
    void queueForRemoval();
    
    
    template <typename T> std::shared_ptr<T> addComponent() {
        //Only a class that derives from Component can be added.
        //This is tested at compile time.
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
        
        //Check that a component of this type does not exist already
        for (auto& existingComponent : components) {
            //Prevent adding the same component twice.
            //This may change in the future
            if (std::dynamic_pointer_cast<T>(existingComponent)) {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }
        
        // The object does not have this component
        // Create it and add it to the list
        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        components.push_back(newComponent);
        
        if (std::dynamic_pointer_cast<CDrawable>(newComponent)) {
            drawable = std::dynamic_pointer_cast<CDrawable>(newComponent);
        }
        
        return newComponent;
    };
    
    template <typename T> std::shared_ptr<T> getComponent() {
        static_assert(std::is_base_of<Component, T>:: value, "T must derive from Component");
        
        for (auto& existingComponent : components) {
            if(std::dynamic_pointer_cast<T>(existingComponent)) {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }
        return nullptr;
    }
    
    std::shared_ptr<CDrawable> getDrawable();
    
private:
    std::vector<std::shared_ptr<Component>> components;
    std::shared_ptr<CDrawable> drawable;
    bool queuedForRemoval;
};

#endif /* Object_hpp */
