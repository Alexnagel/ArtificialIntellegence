//
//  Edge.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Edge.h"
#include "Vertex.h"

Edge::Edge(std::shared_ptr<Vertex> p_origin, std::shared_ptr<Vertex> p_destination, int p_weight)
{
    origin = p_origin;
    destination = p_destination;
    weight = p_weight;
}

std::shared_ptr<Vertex> Edge::getOrigin()
{
    return origin.lock();
}

std::shared_ptr<Vertex> Edge::getDestination()
{
    return destination.lock();
}

int Edge::getWeight()
{
    return weight;
}