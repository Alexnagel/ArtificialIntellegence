//
//  Chicken.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Chicken.h"

Chicken::Chicken()
{
    imageURI = QCoreApplication::applicationDirPath() + "/chicken.png";
}

void Chicken::setPosition(std::shared_ptr<Vertex> vertex)
{
    position = vertex;
}

std::shared_ptr<Vertex> Chicken::getPosition()
{
    return position.lock();
}

QString Chicken::getImageURI()
{
    return imageURI;
}

Chicken::~Chicken()
{
    
}