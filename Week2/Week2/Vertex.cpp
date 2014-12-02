//
//  Vertex.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int p_xpos, int p_ypos, bool isWall, bool p_hasPill) :xpos(p_xpos), ypos(p_ypos), wall(isWall), has_pill(p_hasPill)
{
    if (p_hasPill)
        pill = Pill();
    
    is_destination = false;
}


Vertex::Vertex(int p_xpos, int p_ypos, bool isWall) :xpos(p_xpos), ypos(p_ypos), wall(isWall)
{
    is_destination = false;
}

Vertex::Vertex(const Vertex& vertex) :xpos(vertex.xpos), ypos(vertex.ypos), wall(vertex.wall), has_pill(vertex.has_pill), is_destination(vertex.is_destination)
{
    
}

bool Vertex::isDestination()
{
    return is_destination;
}

void Vertex::setDestination(bool destination)
{
    is_destination = destination;
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

int Vertex::getXpos()
{
    return xpos;
}

int Vertex::getYpos()
{
    return ypos;
}

bool Vertex::isWall()
{
    return wall;
}

bool Vertex::hasPill()
{
    return has_pill;
}

void Vertex::eatPill()
{
    pill.isEaten();
    has_pill = false;
}

bool Vertex::hasCow()
{
    return has_cow;
}

bool Vertex::hasChicken()
{
    return has_chicken;
}

void Vertex::setHasCow(bool hasCow)
{
    has_cow = hasCow;
}

void Vertex::setHasChicken(bool hasChicken)
{
    has_chicken = hasChicken;
}

std::vector<std::shared_ptr<Edge>> Vertex::getEdges()
{
    return edges;
}
