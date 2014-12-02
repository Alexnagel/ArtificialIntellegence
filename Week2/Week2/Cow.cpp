//
//  Cow.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Cow.h"
#include "Graph.h"

Cow::Cow(std::shared_ptr<Graph> p_graph) : Unit()
{
    std::string appPath = QCoreApplication::applicationDirPath().toStdString();
    Unit::imagePath =  appPath.append("/cow.png");
    graph = p_graph;
    has_weapon = false;
    
    // set to wandering
    changeState(StateEnum::CowWander);
}

Cow::Cow(const Cow & other): Unit(other)
{
    
}

void Cow::move(std::shared_ptr<Vertex> vertex)
{
    if (!position.expired())
        position.lock()->setCow(std::shared_ptr<Cow>());
    
    vertex->setCow(shared_from_this());
    position = vertex;
}

void Cow::move()
{
    state->move();
    state->checkState();
}

std::shared_ptr<Vertex> Cow::getPosition()
{
    return position.lock();
}

std::string Cow::getImageURI()
{
    return imagePath;
}

bool Cow::hasWeapon()
{
    return has_weapon;
}

void Cow::setWeapon(bool isWeapon)
{
    has_weapon = isWeapon;
}

StateEnum Cow::getState()
{
    return currentState;
}

void Cow::changeState(StateEnum changeToState)
{
    switch (changeToState) {
        case StateEnum::CowChasing:
            state = new CowChase(std::shared_ptr<Cow>(this));
            currentState = StateEnum::CowChasing;
            break;
        case StateEnum::CowWander:
            state = new CowWandering(std::shared_ptr<Cow>(this));
            currentState = StateEnum::CowWander;break;
        case StateEnum::CowJumping:
            state = new CowJump(std::shared_ptr<Cow>(this));
            currentState = StateEnum::CowJumping; break;
        default:
            break;
    }
}

std::vector<std::shared_ptr<Vertex>> Cow::getRoute()
{
    return state->getRoute();
}

std::vector<std::shared_ptr<Vertex>> Cow::getRouteRandom()
{
    return graph->getRouteRandom(getPosition());
}

std::vector<std::shared_ptr<Vertex>> Cow::getRouteToChicken()
{
    return graph->getRouteChicken(getPosition());
}

std::shared_ptr<Vertex> Cow::getRandomVertex()
{
    return graph->getRandomVertex();
}