//
//  Vertex.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Vertex__
#define __Week1__Vertex__

#include <vector>
#include <memory>

#include "Pill.h"

class Edge;

class Vertex : public std::enable_shared_from_this<Vertex>{
public:
    Vertex(int xpos, int ypos, bool isWall, bool hasPill);
    Vertex(int _id, int xpos, int ypos, bool isWall, bool hasPill);
    Vertex(int xpos, int ypos, bool isWall);
    Vertex(const Vertex& vertex);
    
    void addEdge(std::shared_ptr<Vertex> to, int weight);
    void addEdges(std::shared_ptr<Vertex> to, int weight);
    std::vector<std::shared_ptr<Edge>> getEdges();
    
    int getXpos();
    int getYpos();
    
    bool isWall();
    bool hasPill();
    void eatPill();
    
    bool hasCow();
    bool hasChicken();
    void setHasCow(bool hasCow);
    void setHasChicken(bool hasChicken);
    
    bool isDestination();
    void setDestination(bool destination);
private:
    std::vector<std::shared_ptr<Edge>> edges;
    
    int xpos;
    int ypos;
    bool wall;
    
    Pill pill;
    bool has_pill;
    
    bool has_cow;
    bool has_chicken;
    
    bool is_destination;
};


#endif /* defined(__Week1__Vertex__) */
