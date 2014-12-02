//
//  Chicken.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Chicken.h"
#include "Graph.h"

Chicken::Chicken(std::shared_ptr<Graph> p_graph)
{
    graph = p_graph;
    
    imageURI = QCoreApplication::applicationDirPath() + "/chicken.png";
    changeState(StateEnum::ChickenWander);
}

void Chicken::move(std::shared_ptr<Vertex> vertex)
{
    if (!position.expired())
        position.lock()->setHasChicken(false);
    
    vertex->setHasChicken(true);
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

QString Chicken::getImageURI()
{
    return imageURI;
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
        case StateEnum::ChickenWander:
            state = new ChickenWandering(std::shared_ptr<Chicken>(this));
            currentState = StateEnum::ChickenWander;
        default:
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

Chicken::~Chicken()
{
    
}