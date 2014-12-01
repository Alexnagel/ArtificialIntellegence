//
//  BaseState.h
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__BaseState__
#define __Week2__BaseState__

#include <memory>
#include <vector>

#include "Vertex.h"
#include "Utils.h"
#include "StateEnum.h"

class Unit;
class BaseState {
public:
    virtual void move() = 0;
    virtual void checkState() = 0;
    
protected:
    std::shared_ptr<Unit> owner;
};

#endif /* defined(__Week2__BaseState__) */
