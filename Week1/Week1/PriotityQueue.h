//
//  PriotityQueue.h
//  Week1
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__PriotityQueue__
#define __Week1__PriotityQueue__

#include <queue>
#include "Vertex.h"

class PriorityQueue {
public:
    void put(std::shared_ptr<Vertex> vertex, int priority);
    bool empty();
    std::shared_ptr<Vertex> get();
private:
    typedef std::pair<int, std::shared_ptr<Vertex>> vPair;
    std::priority_queue<vPair, std::vector<vPair>, std::greater<vPair>> elements;
};

#endif /* defined(__Week1__PriotityQueue__) */
