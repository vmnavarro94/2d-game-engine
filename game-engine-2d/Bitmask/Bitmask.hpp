//
//  Bitmask.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-13.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Bitmask_hpp
#define Bitmask_hpp

#include <stdint.h>

class Bitmask {
public:
    Bitmask();
    Bitmask(uint32_t bits);
    //Overrides this bitmask
    void setMask(Bitmask& bitmask);
    // Returns binary representation of bitmask
    uint32_t getMask() const;
    // Returns true ifbit at pos = 1, else false
    bool getBit(int pos) const;
    // Sets bit at specified pos to 1 or 0 (true || false)
    void setBit(int pos, bool value);
    // Sets bit at pos to 1
    void setBit(int pos);
    // Sets bit at pos to 0
    void clearBit(int pos);
    // Sets all bits to 0
    void clear();
private:
    uint32_t bits;
};

#endif /* Bitmask_hpp */
