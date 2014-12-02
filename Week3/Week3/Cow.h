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

class Cow : public Unit, public std::enable_shared_from_this<Unit>{
public:
    Cow(std::shared_ptr<Graph> graph);
    virtual ~Cow();
    
    void move(std::shared_ptr<Vertex> vertex);
    void move();
    std::shared_ptr<Vertex> getPosition();
    QString getImageURI();
    
    void changeState(StateEnum changeToState);
    StateEnum getState();
    
    std::vector<std::shared_ptr<Vertex>> getRouteRandom();
    std::vector<std::shared_ptr<Vertex>> getRouteToChicken();
    std::shared_ptr<Vertex> getRandomVertex();
    
    // DEBUG
    std::vector<std::shared_ptr<Vertex>> getRoute();
};

#endif /* defined(__Week1__Cow__) */
