//
//  ChickenWandering.h
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__ChickenWandering__
#define __Week2__ChickenWandering__

#include "BaseState.h"

class ChickenWandering : public BaseState {
public:
    ChickenWandering(std::shared_ptr<Unit> owner);
    
    void move();
    void checkState();
    std::vector<std::shared_ptr<Vertex>> getRoute();
    
private:
    bool hasRoute;
    int currentIndex;
};

#endif /* defined(__Week2__ChickenWandering__) */
