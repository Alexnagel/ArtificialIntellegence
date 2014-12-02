//
//  Chicken.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Chicken.h"
#include "Graph.h"

Chicken::Chicken(std::shared_ptr<Graph> p_graph): Unit()
{
    std::string appPath = QCoreApplication::applicationDirPath().toStdString();
    Unit::imagePath =  appPath.append("/chicken.png");
    graph = p_graph;
    has_weapon = false;
    
    // Set state to wander
    changeState(StateEnum::ChickenWander);
}

Chicken::Chicken(const Chicken & other) : Unit(other)
{
    
}

void Chicken::move(std::shared_ptr<Vertex> vertex)
{
    if (!position.expired())
        position.lock()->setChicken(std::shared_ptr<Chicken>());
    
    vertex->setChicken(shared_from_this());
    position = vertex;
}

void Chicken::move()
{
    state->checkState();
    state->move();
}

std::shared_ptr<Vertex> Chicken::getPosition()
{
    return position.lock();
}

std::string Chicken::getImageURI()
{
    return Unit::imagePath;
}

bool Chicken::hasWeapon()
{
    return has_weapon;
}

void Chicken::setWeapon(bool isWeapon)
{
    has_weapon = isWeapon;
}

StateEnum Chicken::getState()
{
    return currentState;
}

void Chicken::changeState(StateEnum changeStateTo)
{
    switch (changeStateTo) {
        case StateEnum::ChickenRunning:
            state = new ChickenRun(std::shared_ptr<Chicken>(this));
            currentState = StateEnum::ChickenRunning;
            break;
        case StateEnum::ChickenJumping:
            state = new ChickenJump(std::shared_ptr<Chicken>(this));
            currentState = StateEnum::ChickenJumping;
            break;
        case StateEnum::ChickenWander:
        default:
            state = new ChickenWandering(std::shared_ptr<Chicken>(this));
            currentState = StateEnum::ChickenWander;
            break;
    }
}

std::vector<std::shared_ptr<Vertex>> Chicken::getRouteRandom()
{
    return graph->getRouteRandom(getPosition());
}

std::vector<std::shared_ptr<Vertex>> Chicken::getRouteToChicken()
{
    return graph->getRouteChicken(getPosition());
}

std::shared_ptr<Vertex> Chicken::getRandomVertex()
{
    return graph->getRandomVertex();
}