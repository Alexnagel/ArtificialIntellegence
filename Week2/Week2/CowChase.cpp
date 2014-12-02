//
//  CowChase.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "CowChase.h"
#include "Unit.h"

CowChase::CowChase(std::shared_ptr<Unit> p_owner)
{
    owner = p_owner;
    currentIndex = -1;
}

void CowChase::move()
{
    if (!routedefined || currentIndex >= route.size())
    {
        route = owner->getRouteToChicken();
        routedefined = true;
        currentIndex = -1;
    }
    currentIndex++;
    owner->move(route[currentIndex]);
}

void CowChase::checkState()
{
    if (currentIndex == route.size() - 1)
        owner->changeState(StateEnum::CowWander);
}

std::vector<std::shared_ptr<Vertex>> CowChase::getRoute()
{
    return route;
}