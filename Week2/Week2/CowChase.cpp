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
}

void CowChase::move()
{
    route = owner->getRouteToChicken();
    owner->move(route[0]);
}

void CowChase::checkState()
{
    if (owner->getPosition()->hasChicken())
        owner->changeState(StateEnum::CowWander);
}

std::vector<std::shared_ptr<Vertex>> CowChase::getRoute()
{
    return route;
}