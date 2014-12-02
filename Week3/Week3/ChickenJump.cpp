//
//  ChickenJump.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 02-12-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "ChickenJump.h"
#include "Unit.h"

ChickenJump::ChickenJump(std::shared_ptr<Unit> p_owner)
{
    owner = p_owner;
}

void ChickenJump::move()
{
    moveTo = owner->getRandomVertex();
    owner->move(moveTo);
}

void ChickenJump::checkState()
{
    if (owner->getPosition() == moveTo)
        owner->changeState(StateEnum::ChickenWander);
}

std::vector<std::shared_ptr<Vertex>> ChickenJump::getRoute()
{
    return route;
}