//
//  CDrawable.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-17.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "CDrawable.hpp"

CDrawable::CDrawable() : sortOrder(0) {}

CDrawable::~CDrawable() {}

void CDrawable::setSortOrder(int order) {
    sortOrder = order;
}

int CDrawable::getSortOrder() const {
    return sortOrder;
}
