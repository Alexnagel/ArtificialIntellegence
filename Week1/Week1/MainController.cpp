//
//  Controller.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "MainController.h"

MainController::MainController()
{
    initGraph();
    
    mainWindow = new MainWindow(this);
    
    mainWindow->setGraph(graph);
    mainWindow->setUnits(cow, chicken);
    
    mainWindow->resize(650, 350);
    mainWindow->show();
}

void MainController::move()
{
    update();
}

void MainController::initGraph()
{
    std::shared_ptr<Vertex> vertex1 = graph.addVertex(50, 90, 1);
    std::shared_ptr<Vertex> vertex2 = graph.addVertex(300, 100, 2);
    std::shared_ptr<Vertex> vertex3 = graph.addVertex(150, 200, 3);
    std::shared_ptr<Vertex> vertex4 = graph.addVertex(400, 300, 4);
    std::shared_ptr<Vertex> vertex5 = graph.addVertex(600, 200, 5);
    std::shared_ptr<Vertex> vertex6 = graph.addVertex(300, 20, 6);
    vertices = std::vector<std::shared_ptr<Vertex>> {vertex1, vertex2, vertex3, vertex4, vertex5, vertex6};
    
    graph.addEdges(vertex1, vertex3);
    graph.addEdges(vertex2, vertex4);
    graph.addEdges(vertex3, vertex4);
    graph.addEdges(vertex4, vertex5);
    graph.addEdges(vertex5, vertex6);
    graph.addEdges(vertex1, vertex6);
    
    cow = std::make_shared<Cow>();
    chicken = std::make_shared<Chicken>();
    cow->setPosition(vertex1);
    chicken->setPosition(vertex4);
    
    graph.getRoute(vertex1, vertex5);
}

void MainController::moveChicken()
{
    int position;
    do{
        position = Utils::randomNumber(vertices.size() - 1);
    }
    while (vertices.at(position) == chicken->getPosition());
    
    chicken->setPosition(vertices.at(position));
}

void MainController::moveCow(std::vector<std::shared_ptr<Vertex>> route)
{
    for (std::shared_ptr<Vertex> vertex : route)
    {
        cow->setPosition(vertex);
        
        repaint();
        
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);
    }
}

void MainController::update()
{
    std::vector<std::shared_ptr<Vertex>> route = graph.getRoute(cow->getPosition(), chicken->getPosition());
    moveCow(route);
    moveChicken();
    repaint();
}

void MainController::repaint()
{
    mainWindow->update();
    qApp->processEvents();
}

MainController::~MainController()
{
    
}