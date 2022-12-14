//
//  WorkingDirectory.cpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-12.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#include "WorkingDirectory.hpp"

WorkingDirectory::WorkingDirectory()
{
    path = "./";
    #ifdef MACOS  // 2
    // Change the default working directory to that of
    // the XCode resource path on MacOS.
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL =
    CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
    {
        CFRelease(resourcesURL);
        chdir(path);
    }
    #endif
}
