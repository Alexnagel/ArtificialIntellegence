//
//  Unit.h
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__Unit__
#define __Week2__Unit__

#include <memory>
#include <QString>

#include "Vertex.h"
#include "BaseState.h"

class Graph;
class Unit {
public:
    virtual void move(std::shared_ptr<Vertex> vertex) = 0;
    virtual void move() = 0;
    virtual std::shared_ptr<Vertex> getPosition() = 0;
    virtual QString getImageURI() = 0;
    virtual void changeState(StateEnum state) = 0;
    virtual StateEnum getState() = 0;
    virtual std::vector<std::shared_ptr<Vertex>> getRouteRandom() = 0;
    virtual std::vector<std::shared_ptr<Vertex>> getRouteToChicken() = 0;
    virtual std::shared_ptr<Vertex> getRandomVertex() = 0;
    
protected:
    std::weak_ptr<Vertex> position;
    QString imageURI;
    BaseState* state;
    StateEnum currentState;
    std::shared_ptr<Graph> graph;
};

#endif /* defined(__Week2__Unit__) */
