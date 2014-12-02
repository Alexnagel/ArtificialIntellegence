//
//  CowChase.h
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week2__CowChase__
#define __Week2__CowChase__

#include "BaseState.h"

class CowChase : public BaseState {
public:
    CowChase(std::shared_ptr<Unit> p_owner);

    void move();
    void checkState();
    
    std::vector<std::shared_ptr<Vertex>> getRoute();
private:
    std::vector<std::shared_ptr<Vertex>> route;
};

#endif /* defined(__Week2__CowChase__) */
