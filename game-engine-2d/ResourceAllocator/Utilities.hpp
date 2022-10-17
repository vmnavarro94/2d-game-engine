//
//  Utilities.hpp
//  game-engine-2d
//
//  Created by Victor Navarro on 2022-10-16.
//  Copyright © 2022 Victor Navarro. All rights reserved.
//

#ifndef Utilities_hpp
#define Utilities_hpp

class Utilities {
public:
    // Used answers from:
    // https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
    //TODO: not robust. Only correctly handles whole positive numbers
    static inline bool isInteger(const std::string & s)
    {
        if (s.empty()
            || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        {
            return false;
        }
        
        char * p;
        strtol(s.c_str(), &p, 10);
        return (*p == 0);
    }
};

#endif /* Utilities_hpp */
