//
//  Vertex.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Vertex.h"
#include "Edge.h"
#include "Cow.h"
#include "Chicken.h"

Vertex::Vertex(int p_xpos, int p_ypos, bool isWall, bool p_hasPill, bool p_hasWeapon) :xpos(p_xpos), ypos(p_ypos), wall(isWall), has_pill(p_hasPill), has_weapon(p_hasWeapon)
{
    if (p_hasPill)
        pill = Pill();
    
    is_destination = false;
}


Vertex::Vertex(int p_xpos, int p_ypos, bool isWall) :xpos(p_xpos), ypos(p_ypos), wall(isWall)
{
    is_destination = false;
    has_pill = false;
    has_weapon = false;
}

Vertex::Vertex(const Vertex& vertex) :xpos(vertex.xpos), ypos(vertex.ypos), wall(vertex.wall), has_pill(vertex.has_pill), is_destination(vertex.is_destination), has_weapon(vertex.has_weapon), cow(vertex.cow), chicken(vertex.chicken)
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

bool Vertex::hasWeapon()
{
    return has_weapon;
}

void Vertex::takeWeapon()
{
    has_weapon = false;
}

bool Vertex::hasCow()
{
    return !cow.expired();
}

bool Vertex::hasChicken()
{
    return !chicken.expired();
}

void Vertex::setCow(std::shared_ptr<Cow> p_cow)
{
    cow = p_cow;
}

void Vertex::setChicken(std::shared_ptr<Chicken> p_chicken)
{
    chicken = p_chicken;
}

std::shared_ptr<Cow> Vertex::getCow()
{
    return cow.lock();
}

std::shared_ptr<Chicken> Vertex::getChicken()
{
    return chicken.lock();
}

std::vector<std::shared_ptr<Edge>> Vertex::getEdges()
{
    return edges;
}
