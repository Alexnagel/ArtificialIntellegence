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

class CowWandering : public BaseState{
public:
    CowWandering(std::shared_ptr<Unit> owner);
    
    void move();
    void checkState();
    
    std::vector<std::shared_ptr<Vertex>> getRoute();
private:
    int steps;
    
    bool hasRoute;
    int currentIndex;
};

#endif /* defined(__Week2__CowWandering__) */
