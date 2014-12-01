//
//  CowWandering.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "CowWandering.h"
#include "Unit.h"
#include "Edge.h"

CowWandering::CowWandering(std::shared_ptr<Unit> p_owner, std::shared_ptr<Graph> p_graph)
{
    owner = p_owner;
    steps = 0;
    hasRoute = false;
    this->graph = p_graph;
    currentIndex = 0;
}

void CowWandering::move()
{
    if (currentIndex >= route.size())
    {
        hasRoute = false;
        currentIndex = 0;
        owner->getPosition()->setDestination(false);
    }
    
    if (!hasRoute)
    {
        route = graph->getRouteRandom(owner->getPosition());
        hasRoute = true;
    }
    
    owner->move(route[currentIndex]);
    currentIndex++;
    steps++;
}

void CowWandering::checkState()
{
    //if (owner->getPosition()->hasPill())
    if (steps == 100)
        owner->changeState(StateEnum::CowChasing);
}

std::vector<std::shared_ptr<Vertex>> CowWandering::getRoute()
{
    return route;
}