//
//  DrawableSystem.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-17.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "DrawableSystem.hpp"

void DrawableSystem::add(std::vector<std::shared_ptr<Object>> &objects) {
    for (auto object : objects) {
        add(object);
    }
    sort();
}

void DrawableSystem::add(std::shared_ptr<Object> object) {
    std::shared_ptr<CDrawable> draw = object->getDrawable();
    if (draw) {
        drawables.emplace_back(object);
    }
}

void DrawableSystem::sort()
{
    std::sort(drawables.begin(), drawables.end(), [](std::shared_ptr<Object> a, std::shared_ptr<Object> b) -> bool {
            return a->getDrawable()->getSortOrder() < b->getDrawable()->getSortOrder();
        });
}

void DrawableSystem::draw(Window &window) {
    for (auto& drawable : drawables) {
        drawable->draw(window);
    }
}

void DrawableSystem::processRemovals() {
    auto objectIterator = drawables.begin();
    while (objectIterator != drawables.end()) {
        auto object = *objectIterator;
        if (object->isQueuedForRemoval()) {
            objectIterator = drawables.erase(objectIterator);
        } else {
            objectIterator++;
        }
    }
}
