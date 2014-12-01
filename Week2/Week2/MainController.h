//
//  Controller.h
//  Week2
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

class Cow;
class Chicken;
class MainController : QObject {
    Q_OBJECT
    
    typedef std::vector<std::vector<std::shared_ptr<Vertex>>> verticeVector;
public:
    MainController();
    virtual ~MainController();
    
    void move();
    std::shared_ptr<verticeVector> getVertices();
    void run();
private:
    bool isRunning;
    MainWindow* mainWindow;
    std::shared_ptr<Graph> graph;
    int width,
    height;
    
    std::shared_ptr<verticeVector> vertices;
    std::shared_ptr<Cow> cow;
    std::shared_ptr<Chicken> chicken;
    
    void update();
    void repaint();
    void initGraph();
    void moveChicken();
    void moveCow(std::vector<std::shared_ptr<Vertex>> route);
};

#endif /* defined(__Week1__Controller__) */
