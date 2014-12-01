//
//  Cow.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Cow.h"

Cow::Cow(std::shared_ptr<Graph> graph)
{
    imageURI = QCoreApplication::applicationDirPath() + "/cow.png";
    this->graph = graph;
    
    // set to wandering
    changeState(StateEnum::CowWander);
}

Cow::Cow(const Cow& rvalue):graph(rvalue.graph)
{
    
}

void Cow::move(std::shared_ptr<Vertex> vertex)
{
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
            state = new CowChase(std::shared_ptr<Cow>(this), graph);
            currentState = StateEnum::CowChasing;
            break;
        case StateEnum::CowWander:
            state = new CowWandering(std::shared_ptr<Cow>(this), graph);
            currentState = StateEnum::CowWander;
        default:
            break;
    }
}

std::vector<std::shared_ptr<Vertex>> Cow::getRoute()
{
    return state->getRoute();
}

Cow::~Cow()
{
    
}