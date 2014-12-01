//
//  Utils.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Utils.h"

int Utils::seed = std::random_device()();
std::mt19937 Utils::rng = std::mt19937(Utils::seed);

Utils::Utils()
{
    
}

int Utils::randomNumber(int max)
{
    return std::uniform_int_distribution<int>(0, max)(rng);
}

int Utils::randomNumber(int min, int max)
{
    return std::uniform_int_distribution<int>(min, max)(rng);
}

int Utils::max(int x, int y)
{
    return x - ((x - y) & ((x - y) >>
                           (sizeof(int) * CHAR_BIT - 1)));
}

Utils::~Utils()
{
    
}