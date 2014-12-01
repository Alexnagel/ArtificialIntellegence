//
//  CowChase.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "CowChase.h"
#include "Unit.h"

CowChase::CowChase(std::shared_ptr<Unit> p_owner, std::shared_ptr<Graph> graph)
{
    owner = p_owner;
    this->graph = graph;
    currentIndex = 0;
}

void CowChase::move()
{
    if (!routedefined)
    {
        route = graph->getRouteChicken(owner->getPosition());
        routedefined = true;
        currentIndex = 0;
    }
    owner->move(route[currentIndex]);
    currentIndex++;
}

void CowChase::checkState()
{
    if (currentIndex == route.size() - 1)
        owner->changeState(StateEnum::CowWander);
}