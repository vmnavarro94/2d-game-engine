//
//  CInstanceId.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-24.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef CInstanceId_hpp
#define CInstanceId_hpp

#include "Component.hpp"

class CInstanceId : public Component {
public:
    CInstanceId(Object* owner);
    ~CInstanceId();
    int get() const;

private:
    static int count;
    int id;
};

#endif /* CInstanceId_hpp */
