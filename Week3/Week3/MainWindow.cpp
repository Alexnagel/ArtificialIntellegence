 //
//  MainWindow.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "MainWindow.h"
#include "MainController.h"
#include "Cow.h"
#include "Chicken.h"
#include "Graph.h"
#include "Vertex.h"

MainWindow::MainWindow(QWidget *parent)
{
    
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    controller->quit();
    event->accept();
}

void MainWindow::setController(MainController* p_controller)
{
    controller = p_controller;
}

void MainWindow::setGraph(std::shared_ptr<Graph> p_graph)
{
    graph = p_graph;
}

void MainWindow::setUnits(std::shared_ptr<Cow> p_cow, std::shared_ptr<Chicken> p_chicken)
{
    cow = p_cow;
    chicken = p_chicken;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    drawMap();
    drawSearch();
    drawUnits();
    drawStateText();
    
}

void MainWindow::drawMap()
{
    QPainter painter(this);
    painter.setBrush(Qt::darkGreen);
    painter.setPen(Qt::NoPen);
    
    for (std::vector<std::shared_ptr<Vertex>> xgrid : graph->getVertices())
    {
        for (std::shared_ptr<Vertex> vertex : xgrid)
        {
            if (vertex->isWall())
                painter.setBrush(Qt::darkBlue);
            if (vertex->isDestination())
                painter.setBrush(Qt::red);
            if (vertex->hasPill())
                painter.setBrush(Qt::darkMagenta);
            if (vertex->hasWeapon())
                painter.setBrush(Qt::yellow);
                
            painter.drawRect(vertex->getXpos(), vertex->getYpos(), 8, 8);

            painter.setBrush(Qt::darkGreen);
            
            if (DRAW_EDGES)
            {
                for (std::shared_ptr<Edge> edge : vertex->getEdges())
                {
                    painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
                    painter.drawLine(edge->getOrigin()->getXpos() + 4, edge->getOrigin()->getYpos() + 4,
                                     edge->getDestination()->getXpos() + 4, edge->getDestination()->getYpos() + 4);
                }
            }
            
            painter.setPen(Qt::NoPen);
        }
    }
}

void MainWindow::setPaths(std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex> > p_paths)
{
    paths = p_paths;
}

void MainWindow::drawSearch()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
    for (std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> pair : paths )
    {
        std::shared_ptr<Vertex> first, second;
        first = pair.first;
        second = pair.second;
        painter.drawLine(first->getXpos() + 4, first->getYpos() + 4,
                         second->getXpos() + 4, second->getYpos() + 4);
    }
}

void MainWindow::drawUnits()
{
    QPainter painter(this);
    
    std::shared_ptr<Cow> s_cow = cow.lock();
    std::shared_ptr<Chicken> s_chicken = chicken.lock();
    QImage chicken_img(QString::fromStdString(s_chicken->getImageURI()));
    QImage cow_img(QString::fromStdString(s_cow->getImageURI()));
    
    cow_img = cow_img.scaled(30, 30, Qt::KeepAspectRatio);
    chicken_img = chicken_img.scaled(30, 30, Qt::KeepAspectRatio);
    
    painter.drawImage(s_chicken->getPosition()->getXpos() - 15,
                      s_chicken->getPosition()->getYpos() - 15, chicken_img);
    
    painter.drawImage(s_cow->getPosition()->getXpos() - 15,
                      s_cow->getPosition()->getYpos() - 15, cow_img);
    
    if (DRAW_COW_PATH)
    {
        painter.setPen(QPen(Qt::yellow, 2, Qt::SolidLine));
        std::vector<std::shared_ptr<Vertex>> route = s_cow->getRoute();
        for (int i = 0; i < route.size(); i++)
        {
            if (i < route.size() - 1)
                painter.drawLine(route[i]->getXpos() + 4, route[i]->getYpos() + 4,
                                 route[i + 1]->getXpos() + 4, route[i + 1]->getYpos() + 4);
        }
        painter.setPen(Qt::NoPen);
    }
}

void MainWindow::drawStateText()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    
    QString stateTextCow;
    switch (cow.lock()->getState()) {
        case StateEnum::CowChasing:
            stateTextCow = "Cow is chasing the chicken";
            break;
        case StateEnum::CowWander:
        default:
            stateTextCow = "Cow is wandering in the field";
            break;
    }
    painter.drawText(20, this->height() - 20, stateTextCow);
    
    QString stateTextChicken;
    switch (chicken.lock()->getState()) {
        case StateEnum::ChickenRunning:
            stateTextChicken = "Chicken is fleeing";
            break;
        case StateEnum::ChickenWander:
        default:
            stateTextChicken = "Chicken is wandering";
            break;
    }
    
    if (chicken.lock()->hasWeapon())
        stateTextChicken.append(". Has Weapon");
    
    painter.drawText(this->width() - 400, this->height() - 20, stateTextChicken);
}



MainWindow::~MainWindow()
{
    delete controller;
}