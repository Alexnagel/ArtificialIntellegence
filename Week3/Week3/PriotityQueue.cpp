//
//  PriotityQueue.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "PriotityQueue.h"

void PriorityQueue::put(std::shared_ptr<Vertex> vertex, int priority)
{
    elements.emplace(priority, vertex);
}

std::shared_ptr<Vertex> PriorityQueue::get()
{
    std::shared_ptr<Vertex> item = elements.top().second;
    elements.pop();
    return item;
}

bool PriorityQueue::empty()
{
    return elements.empty();
}