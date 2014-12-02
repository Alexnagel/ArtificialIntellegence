//
//  Chicken.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Chicken__
#define __Week1__Chicken__

#include <QCoreApplication>

#include "Unit.h"
#include "ChickenWandering.h"
#include "ChickenRun.h"

class Chicken : public Unit, public std::enable_shared_from_this<Unit>{
public:
    Chicken(std::shared_ptr<Graph> graph);
    virtual ~Chicken();
    
    void move(std::shared_ptr<Vertex> vertex);
    void move();
    std::shared_ptr<Vertex> getPosition();
    QString getImageURI();
    
    void changeState(StateEnum state);
    StateEnum getState();
    
    std::vector<std::shared_ptr<Vertex>> getRouteRandom();
    std::vector<std::shared_ptr<Vertex>> getRouteToChicken();
    std::shared_ptr<Vertex> getRandomVertex();
};

#endif /* defined(__Week1__Chicken__) */
