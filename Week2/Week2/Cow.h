//
//  Cow.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Cow__
#define __Week1__Cow__

#include <memory>
#include <QString>
#include <QCoreApplication>

#include "Vertex.h"

class Cow {
public:
    Cow();
    virtual ~Cow();
    
    void setPosition(std::shared_ptr<Vertex> vertex);
    std::shared_ptr<Vertex> getPosition();
    QString getImageURI();
    
private:
    QString imageURI;
    std::weak_ptr<Vertex> position;
};

#endif /* defined(__Week1__Cow__) */
