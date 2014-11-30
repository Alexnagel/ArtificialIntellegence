//
//  Cow.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Cow.h"

Cow::Cow()
{
    imageURI = QCoreApplication::applicationDirPath() + "/cow.png";
}

void Cow::setPosition(std::shared_ptr<Vertex> vertex)
{
    position = vertex;
}

std::shared_ptr<Vertex> Cow::getPosition()
{
    return position.lock();
}

QString Cow::getImageURI()
{
    return imageURI;
}

Cow::~Cow()
{
    
}