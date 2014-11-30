//
//  main.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include <QApplication>
#include "MainController.h"

int main(int argc, const char * argv[]) {
    QApplication app(argc, 0);
    MainController mainController;
    app.exec();
}
