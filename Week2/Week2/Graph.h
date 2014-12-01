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
#include <algorithm>
#include <iostream>

#include "Vertex.h"
#include "Edge.h"
#include "Utils.h"
#include "PriotityQueue.h"
#include "Chicken.h"
#include "MainWindow.h"

class Cow;

class Graph{
public:
    Graph(MainWindow* main);
    Graph(const Graph& rvalue);
    
    std::shared_ptr<Vertex> addVertex(int xpos, int ypos, bool isWall, bool hasPill);
    void addEdge(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to);
    void addEdges(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to);
    void addEdges(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to, int weight);
    std::vector<std::vector<std::shared_ptr<Vertex>>> getVertices();
    void setVertices(std::shared_ptr<std::vector<std::vector<std::shared_ptr<Vertex>>>> vertices);
    
    int getWidth();
    int getHeight();
    
    void setUnits(std::shared_ptr<Chicken> chicken);
    
    std::vector<std::shared_ptr<Vertex>> getRoute(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);
    std::vector<std::shared_ptr<Vertex>> getRouteRandom(std::shared_ptr<Vertex> start);
    std::vector<std::shared_ptr<Vertex>> getRouteChicken(std::shared_ptr<Vertex> start);
    
private:
    static const bool DEBUG_PATH = false;
    
    std::shared_ptr<Chicken> chicken;
    std::shared_ptr<std::vector<std::vector<std::shared_ptr<Vertex>>>> vertices;
    std::vector<std::shared_ptr<Vertex>> closedList;
    std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>>* cameFrom;
    
    std::vector<std::shared_ptr<Vertex>> createPath(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);
    int calculateHeuristic(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);
    MainWindow* main;
};

#endif /* defined(__Week1__Graph__) */
