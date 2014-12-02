//
//  Unit.cpp
//  Week2
//
//  Created by Alex Nagelkerke on 30-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Unit.h"
#include "Graph.h"

Unit::Unit()
{
}

Unit::Unit(const Unit & other): position(other.position), imagePath(other.imagePath), state(other.state), currentState(other.currentState), graph(other.graph), has_weapon(other.has_weapon)
{
}