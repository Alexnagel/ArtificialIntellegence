//
//  ChickenWandering.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "ChickenWandering.h"
#include "Unit.h"

ChickenWandering::ChickenWandering(std::shared_ptr<Unit> p_owner)
{
    owner = p_owner;
    currentIndex = 0;
}

void ChickenWandering::move()
{
    if (currentIndex >= route.size())
    {
        hasRoute = false;
        currentIndex = 0;
    }
    
    if (!hasRoute)
    {
        route = owner->getRouteRandom();
        hasRoute = true;
    }
    
    
    owner->move(route[currentIndex]);
    currentIndex++;
    
    // Check for weapon
    if (owner->getPosition()->hasWeapon() && !owner->hasWeapon())
    {
        owner->setWeapon(true);
        owner->getPosition()->takeWeapon();
    }
}

void ChickenWandering::checkState()
{
    // Don't know this one
    // MainController doing this one
}

std::vector<std::shared_ptr<Vertex>> ChickenWandering::getRoute()
{
    return route;
}