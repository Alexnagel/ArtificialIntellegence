//
//  Utils.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Utils__
#define __Week1__Utils__

#include <random>

class Utils
{
public:
    Utils();
    virtual ~Utils();
    
    static int randomNumber(int max);
    
private:
    static int seed;
    static std::mt19937 rng;
};

#endif /* defined(__Week1__Utils__) */
