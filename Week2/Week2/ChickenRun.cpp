//
//  ChickenRun.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "ChickenRun.h"

ChickenRun::ChickenRun(std::shared_ptr<Unit> p_owner)
{
    owner = p_owner;
}

void ChickenRun::move()
{
    
}

void ChickenRun::checkState()
{
    
}

std::vector<std::shared_ptr<Vertex>> ChickenRun::getRoute()
{
    return route;
}