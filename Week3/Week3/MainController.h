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
#include <cmath>
#include <iostream>

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
    
    void quit();
private:
    static const int BOX_SIZE = 8;
    static const int BOX_AMOUNT = 5;
    static const int TILE_SIZE = 40;
    
    std::unique_ptr<std::thread> gameLoop;
    
    int width;
    int height;
    int xGrid;
    int yGrid;
    
    bool isRunning;
    MainWindow* mainWindow;
    std::shared_ptr<Graph> graph;
    
    std::shared_ptr<Cow> cow;
    std::shared_ptr<Chicken> chicken;
    
    void update();
    void repaint();
    void initGraph();
    void initUnits();
    
    // move
    void moveChicken();
    void moveCow(std::vector<std::shared_ptr<Vertex>> route);
};

#endif /* defined(__Week1__Controller__) */
