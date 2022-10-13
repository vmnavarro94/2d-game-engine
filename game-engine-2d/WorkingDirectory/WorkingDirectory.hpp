//
//  WorkingDirectory.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef WorkingDirectory_hpp
#define WorkingDirectory_hpp

#include <string>
#ifdef MACOS
#include "CoreFoundation/CoreFoundation.h"
#endif

class WorkingDirectory
{
public:
    WorkingDirectory();
    inline const std::string& get()
    {
        return path;
    }
private:
    std::string path;
};

#endif /* WorkingDirectory_hpp */
