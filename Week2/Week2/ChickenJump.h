//
//  ChickenJump.h
//  Week2
//
//  Created by Alex Nagelkerke on 02-12-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__ChickenJump__
#define __Week2__ChickenJump__

#include "BaseState.h"

class ChickenJump : public BaseState {
public:
    ChickenJump(std::shared_ptr<Unit> owner);
    
    void move();
    void checkState();
    std::vector<std::shared_ptr<Vertex>> getRoute();
    
private:
    std::shared_ptr<Vertex> moveTo;
};

#endif /* defined(__Week2__ChickenJump__) */
