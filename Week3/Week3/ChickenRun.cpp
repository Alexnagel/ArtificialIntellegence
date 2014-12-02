//
//  ChickenRun.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "ChickenRun.h"
#include "Unit.h"
#include "Cow.h"

ChickenRun::ChickenRun(std::shared_ptr<Unit> p_owner)
{
    owner = p_owner;
    usedWeapon = false;
}

void ChickenRun::move()
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
    
    if (owner->hasWeapon())
    {
        int searchAmount = ((route.size() - 15) <= 0) ? 0 : route.size() - 15;
        for (int i = route.size() - 1; i >= searchAmount; i--)
        {
            if (route[i]->hasCow())
            {
                route[i]->getCow()->changeState(StateEnum::CowJumping);
                owner->setWeapon(false);
                usedWeapon = true;
            }
        }
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

void ChickenRun::checkState()
{
    if (owner->getPosition()->hasCow())
        owner->changeState(StateEnum::ChickenJumping);
    else if (usedWeapon)
        owner->changeState(StateEnum::ChickenWander);
}

std::vector<std::shared_ptr<Vertex>> ChickenRun::getRoute()
{
    return route;
}