//
//  Edge.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Edge__
#define __Week1__Edge__
#include <vector>
#include <memory>

class Vertex;

class Edge {
public:
    Edge(std::shared_ptr<Vertex> origin, std::shared_ptr<Vertex> destination, int weight);
    
    std::shared_ptr<Vertex> getOrigin();
    std::shared_ptr<Vertex> getDestination();
    int getWeight();
private:
    std::weak_ptr<Vertex> origin;
    std::weak_ptr<Vertex> destination;
    int weight;
};

#endif /* defined(__Week1__Edge__) */
