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
    height = 520;
    
    // Init MainWindow and set the data
    mainWindow = new MainWindow();
    mainWindow->setController(this);
    
    // Init the graph
    graph = std::make_shared<Graph>(mainWindow);
    initGraph();
    
    // Init the units
    initUnits();
    
    // Set the graph and the units
    mainWindow->setGraph(graph);
    mainWindow->setUnits(cow, chicken);
    
    mainWindow->resize(width, height);
    mainWindow->show();
    
    run();
}

void MainController::quit()
{
    isRunning = false;
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
        
        std::chrono::milliseconds dura(50);
        std::this_thread::sleep_for(dura);
    }
}

void MainController::initGraph()
{
    // Create the two dimensional vector
    std::shared_ptr<verticeVector> vertices = std::make_shared<verticeVector>();
    
    // Calculate the map tiles width and height
    int mapHeight = height / TILE_SIZE;
    int mapWidth = width / TILE_SIZE;
    
    // Calculate the amount of boxes there are
    xGrid = mapWidth * BOX_AMOUNT;
    yGrid = mapHeight * BOX_AMOUNT;
    
    int baseY = 0;
    for (int y = 1; y < mapHeight; y++)
    {
        int baseX = 0;
        for (int x = 1; x < mapWidth; x++)
        {
            bool isWall = false;
            bool hasPill = false;
            
            int randomWall = Utils::randomNumber(100);
            if (randomWall < 20)
                isWall = true;
            
            int randomPill = Utils::randomNumber(100);
            if (randomPill < 35 && !isWall)
                hasPill = true;
            
            int tempY = baseY;
            for (int j = 0; j < BOX_AMOUNT; j++)
            {
                // Check if a new vector should be added
                if ((tempY / BOX_SIZE) >= vertices->size())
                    vertices->push_back(std::vector<std::shared_ptr<Vertex>>());
                
                int tempX = baseX;
                for (int i = 0; i < BOX_AMOUNT; i++)
                {
                    int arrayX = (tempX / BOX_SIZE);
                    int arrayY = (tempY / BOX_SIZE);
                    
                    // Create the vertex and push to vector
                    std::shared_ptr<Vertex> vertex;
                    
                    if (j == std::floor((BOX_SIZE - 1) / 2) && i == std::floor((BOX_SIZE - 1) / 2) && hasPill)
                        vertex = graph->addVertex(tempX, tempY, isWall, hasPill);
                    else
                        vertex = graph->addVertex(tempX, tempY, isWall, false);
                    
                    vertices->at(arrayY).push_back(vertex);
                    
                    // Only connect vertex if it isn't a wall
                    if (!isWall)
                    {
                        if (arrayX > 0 )
                        {
                            // Connect vertex to vertex left of it
                            std::shared_ptr<Vertex> to = vertices->at(arrayY).at(arrayX - 1);
                            if (!to->isWall())
                                graph->addEdges(vertex, to);
                        }
                        if (arrayY > 0)
                        {
                            // Connect vertex to vertex above it
                            std::shared_ptr<Vertex> to = vertices->at(arrayY - 1).at(arrayX);
                            if (!to->isWall())
                                graph->addEdges(vertex, to);
                        }
                        
                        if (arrayX > 0 && arrayY > 0)
                        {
                            // Connect vertex to the vertex left above it
                            std::shared_ptr<Vertex> to = vertices->at(arrayY - 1).at(arrayX - 1);
                            if (!to->isWall())
                                graph->addEdges(vertex, to);
                        }
                    }
                    
                    tempX += BOX_SIZE;
                }
                tempY += BOX_SIZE;
            }
            baseX += (BOX_AMOUNT * BOX_SIZE);
        }
        
        
        // For loop for connecting vertices to the one to the right above of it
        int tempY = baseY;
        for (int j = 0; j < BOX_AMOUNT; j++)
        {
            for (int i = 0; i < mapWidth * BOX_AMOUNT; i++)
            {
                int arrayY = (tempY / BOX_SIZE);
                if (i < ((mapWidth * BOX_AMOUNT) - 6) && arrayY > 0)
                {
                    std::shared_ptr<Vertex> from = vertices->at(arrayY).at(i);
                    std::shared_ptr<Vertex> to = vertices->at(arrayY - 1).at(i + 1);
                    if (!from->isWall() && !to->isWall())
                        graph->addEdges(from, to);
                }
            }
            tempY += BOX_SIZE;
        }
        baseY += (BOX_AMOUNT * BOX_SIZE);
    }
    
    // Set graph vertices
    graph->setVertices(vertices);
}

void MainController::initUnits()
{
    // Get the vertices to init Cow and Chicken
    verticeVector vertices = graph->getVertices();
    
    chicken = std::shared_ptr<Chicken>(new Chicken(graph));
    cow = std::shared_ptr<Cow>(new Cow(graph));
    
    // variables for getting the units
    int cowx, cowy, chickx, chicky;
    std::shared_ptr<Vertex> cowVertex;
    std::shared_ptr<Vertex> chickenVertex;
    int mapHeight = height / TILE_SIZE;
    int mapWidth = width / TILE_SIZE;
    
    // Set the chicken location
    do {
        chickx = Utils::randomNumber(mapWidth - 1);
        chicky = Utils::randomNumber(mapHeight - 1);
        chickenVertex = vertices.at(chicky).at(chickx);
    }
    while (chickenVertex->isWall());
    chicken->move(chickenVertex);
    
    // Set the chicken in the graph
    graph->setUnits(chicken);
    
    // Set the cow location
    do {
        cowx = Utils::randomNumber(mapWidth - 1);
        cowy = Utils::randomNumber(mapHeight - 1);
        cowVertex = vertices.at(cowy).at(cowx);
    }
    while (cowVertex->isWall());
    cow->move(cowVertex);
}

void MainController::update()
{
    // Move the cow
    cow->move();
    
    // Move the chicken
    chicken->move();
    
    // Repaint the main window
    repaint();
}

void MainController::repaint()
{
    mainWindow->update();
    // Dirty but it works
    qApp->processEvents();
}

MainController::~MainController()
{
    delete mainWindow;
}