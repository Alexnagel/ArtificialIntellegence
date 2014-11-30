//
//  Graph.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Graph__
#define __Week1__Graph__

#include <map>

#include "Vertex.h"
#include "Edge.h"
#include "Utils.h"
#include "Cow.h"
#include "Chicken.h"
#include "PriotityQueue.h"

class Graph{
public:
    Graph();
    
    std::shared_ptr<Vertex> addVertex(int xpos, int ypos, int _id);
    void addEdge(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to);
    void addEdges(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to);
    std::vector<std::shared_ptr<Vertex>> getVertices();
    
    std::vector<std::shared_ptr<Vertex>> getRoute(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);
    
private:
    std::vector<std::shared_ptr<Vertex>> vertices;
    std::vector<std::shared_ptr<Vertex>> closedList;
    std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> cameFrom;
    
    std::vector<std::shared_ptr<Vertex>> createPath(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);
    int calculateHeuristic(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);
};

#endif /* defined(__Week1__Graph__) */
