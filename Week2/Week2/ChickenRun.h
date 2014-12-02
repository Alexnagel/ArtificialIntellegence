//
//  ChickenRun.h
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__ChickenRun__
#define __Week2__ChickenRun__

#include "BaseState.h"

class ChickenRun : public BaseState {
public:
    ChickenRun(std::shared_ptr<Unit> p_owner);
    
    void move();
    void checkState();
    std::vector<std::shared_ptr<Vertex>> getRoute();
private:
    std::shared_ptr<Vertex> moveTo;
};

#endif /* defined(__Week2__ChickenRun__) */
