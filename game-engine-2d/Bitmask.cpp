//
//  Bitmask.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "Bitmask.hpp"

Bitmask::Bitmask() : bits(0) {}

void Bitmask::setMask(Bitmask& bitmask) {
    bits = bitmask.getMask();
}

uint32_t Bitmask::getMask() const {
    return bits;
}

bool Bitmask::getBit(int pos) const {
    return (bits & (1 << pos)) != 0;
}

void Bitmask::setBit(int pos, bool value) {
    if (value) {
        setBit(pos);
    } else {
        clearBit(pos);
    }
}

void Bitmask::setBit(int pos) {
    bits = bits | 1 << pos;
}

void Bitmask::clearBit(int pos) {
    bits = bits & ~(1 << pos);
}

void Bitmask::clear() {
    bits = 0;
}
