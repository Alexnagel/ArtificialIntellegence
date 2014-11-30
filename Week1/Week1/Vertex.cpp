//
//  Vertex.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int p_xpos, int p_ypos, int p_id) :xpos(p_xpos), ypos(p_ypos), visited(false), _id(p_id)
{
    
}

Vertex::Vertex(const Vertex& vertex) :xpos(vertex.xpos), ypos(vertex.ypos), visited(vertex.visited), _id(vertex._id)
{
    
}

void Vertex::addEdge(std::shared_ptr<Vertex> to, int weight)
{
    std::shared_ptr<Edge> edge = std::make_shared<Edge>(shared_from_this(), to, weight);
    edges.push_back(edge);
}

void Vertex::addEdges(std::shared_ptr<Vertex> to, int weight)
{
    addEdge(to, weight);
    to->addEdge(shared_from_this(), weight);
}

bool Vertex::isVisited()
{
    return visited;
}

void Vertex::setVisited(bool isVisited)
{
    visited = isVisited;
}

int Vertex::getXpos()
{
    return xpos;
}

int Vertex::getYpos()
{
    return ypos;
}

int Vertex::getId()
{
    return _id;
}

std::vector<std::shared_ptr<Edge>> Vertex::getEdges()
{
    return edges;
}
