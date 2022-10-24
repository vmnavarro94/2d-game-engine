//
//  CInstanceId.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-24.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CInstanceId.hpp"

int CInstanceId::count = 0;

CInstanceId::CInstanceId(Object* owner) : Component(owner), id(count++) {}

CInstanceId::~CInstanceId() {}

int CInstanceId::get() const {
    return id;
}
