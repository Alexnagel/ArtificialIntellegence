//
//  Cow.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Cow__
#define __Week1__Cow__

#include <QCoreApplication>

#include "Unit.h"
#include "CowChase.h"
#include "CowWandering.h"
#include "Graph.h"

class Cow : public Unit, public std::enable_shared_from_this<Unit>{
public:
    Cow(std::shared_ptr<Graph> graph);
    Cow(const Cow& rvalue);
    virtual ~Cow();
    
    void move(std::shared_ptr<Vertex> vertex);
    void move();
    std::shared_ptr<Vertex> getPosition();
    QString getImageURI();
    
    void changeState(StateEnum changeToState);
    StateEnum getState();
    
    // DEBUG
    std::vector<std::shared_ptr<Vertex>> getRoute();
private:
    std::shared_ptr<Graph> graph;
};

#endif /* defined(__Week1__Cow__) */
