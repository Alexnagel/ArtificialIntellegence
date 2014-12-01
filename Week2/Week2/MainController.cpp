//
//  Controller.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "MainController.h"
#include "Cow.h"
#include "Chicken.h"

MainController::MainController()
{
    width = 880;
    height = 800;
    
    graph = std::make_shared<Graph>();
    initGraph();
    mainWindow = new MainWindow();
    
    mainWindow->setController(this);
    mainWindow->setGraph(graph);
    mainWindow->setUnits(cow, chicken);
    
    mainWindow->resize(width, height);
    mainWindow->show();
    
    run();
}

void MainController::run()
{
    double  dt  = 0.0,
    current,
    previous;
    
    isRunning    = true;
    
    current         = ::clock();
    while (isRunning)
    {
        previous    = current;
        current     = ::clock();
        dt          = current - previous;
        
        update();
        
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);
    }
}

void MainController::move()
{
    //update();
}

void MainController::initGraph()
{
    int gridx = width / 40;
    int gridy = height / 40;
    
    vertices = std::make_shared<verticeVector>();
    for (int y = 1; y < gridy; y++)
    {
        std::vector<std::shared_ptr<Vertex>> vrow;
        for (int x = 1; x < gridx; x++)
        {
            bool isWall = false;
            bool hasPill = false;
            int random = Utils::randomNumber(100);
            if (random < 20)
                isWall = true;
            if (random < 10)
                hasPill = true;
            
            std::shared_ptr<Vertex> vertex = graph->addVertex(x * 40, y * 40, isWall);
            vrow.push_back(vertex);
            
            if (x > 1)
                graph->addEdges(vertex, vrow.at(x - 2));
            if (y > 1)
                graph->addEdges(vertex, vertices->at(y - 2).at(x - 1));
        }
        vertices->push_back(vrow);
    }
    graph->setVertices(vertices);
    
    chicken = std::shared_ptr<Chicken>(new Chicken());
    cow = std::shared_ptr<Cow>(new Cow(graph));
    
    int cowx, cowy, chickx, chicky;
    std::shared_ptr<Vertex> cowVertex;
    std::shared_ptr<Vertex> chickenVertex;
    
    // Set the chicken location
    do {
        chickx = Utils::randomNumber(gridx - 2);
        chicky = Utils::randomNumber(gridy - 1);
        chickenVertex = vertices->at(chicky).at(chickx);
    }
    while (chickenVertex->isWall());
    chicken->move(chickenVertex);
    
    // Set the chicken in the graph
    graph->setUnits(chicken);
    
    // Set the cow location
    do {
        cowx = Utils::randomNumber(gridx - 2);
        cowy = Utils::randomNumber(gridy - 1);
        cowVertex = vertices->at(cowy).at(cowx);
    }
    while (cowVertex->isWall());
    cow->move(cowVertex);
}

void MainController::update()
{
    cow->move();
    repaint();
}

void MainController::repaint()
{
    mainWindow->update();
    // Dirty but it works
    qApp->processEvents();
}

std::shared_ptr<std::vector<std::vector<std::shared_ptr<Vertex>>>> MainController::getVertices()
{
    return vertices;
}

MainController::~MainController()
{
    
}