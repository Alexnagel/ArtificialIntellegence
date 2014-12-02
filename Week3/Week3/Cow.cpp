//
//  Cow.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Cow.h"
#include "Graph.h"

Cow::Cow(std::shared_ptr<Graph> graph)
{
    imageURI = QCoreApplication::applicationDirPath() + "/cow.png";
    this->graph = graph;
    
    // set to wandering
    changeState(StateEnum::CowWander);
}

void Cow::move(std::shared_ptr<Vertex> vertex)
{
    if (!position.expired())
        position.lock()->setHasCow(false);
    
    vertex->setHasCow(true);
    position = vertex;
}

void Cow::move()
{
    state->checkState();
    state->move();
}

std::shared_ptr<Vertex> Cow::getPosition()
{
    return position.lock();
}

QString Cow::getImageURI()
{
    return imageURI;
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
            currentState = StateEnum::CowWander;
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
    return std::shared_ptr<Vertex>();
}

Cow::~Cow()
{
    
}