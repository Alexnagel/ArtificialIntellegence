//
//  Controller.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Controller__
#define __Week1__Controller__

#include <QObject>
#include <QtWidgets>
#include <thread>

#include "MainWindow.h"
#include "Graph.h"

class MainController : QObject {
    Q_OBJECT
    
public:
    MainController();
    virtual ~MainController();
    
    void move();
private:
    MainWindow* mainWindow;
    Graph graph;
    
    std::vector<std::shared_ptr<Vertex>> vertices;
    std::shared_ptr<Cow> cow;
    std::shared_ptr<Chicken> chicken;
    
    void update();
    void repaint();
    void initGraph();
    void moveChicken();
    void moveCow(std::vector<std::shared_ptr<Vertex>> route);
};

#endif /* defined(__Week1__Controller__) */
