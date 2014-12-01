//
//  CowWandering.h
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__CowWandering__
#define __Week2__CowWandering__

#include "BaseState.h"
#include "Graph.h"

class CowWandering : public BaseState{
public:
    CowWandering(std::shared_ptr<Unit> owner, std::shared_ptr<Graph> graph);
    
    void move();
    void checkState();
private:
    std::shared_ptr<Graph> graph;
    int steps;
    
    bool hasRoute;
    int currentIndex;
    std::vector<std::shared_ptr<Vertex>> route;
};

#endif /* defined(__Week2__CowWandering__) */
