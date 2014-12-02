//
//  CowJump.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 02-12-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "CowJump.h"
#include "Unit.h"

CowJump::CowJump(std::shared_ptr<Unit> p_owner)
{
    owner = p_owner;
}

void CowJump::move()
{
    moveTo = owner->getRandomVertex();
    owner->move(moveTo);
}

void CowJump::checkState()
{
    if (owner->getPosition() == moveTo)
        owner->changeState(StateEnum::CowWander);
}

std::vector<std::shared_ptr<Vertex>> CowJump::getRoute()
{
    return route;
}