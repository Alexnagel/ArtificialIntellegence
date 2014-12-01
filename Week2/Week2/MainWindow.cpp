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

MainWindow::MainWindow(QWidget *parent)
{
    
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

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Space)
    {
        controller->move();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::darkGreen);
    
    for (std::vector<std::shared_ptr<Vertex>> xgrid : *controller->getVertices())
    {
        for (std::shared_ptr<Vertex> vertex : xgrid)
        {
            if (vertex->isWall())
            {
                painter.setBrush(Qt::darkBlue);
            }
            painter.drawRect(vertex->getXpos() - 25, vertex->getYpos() - 25, 50, 50);
            painter.setBrush(Qt::darkGreen);
        }
    }
    
    std::shared_ptr<Cow> s_cow = cow.lock();
    std::shared_ptr<Chicken> s_chicken = chicken.lock();
    QImage chicken_img(s_chicken->getImageURI());
    QImage cow_img(s_cow->getImageURI());
    
    cow_img = cow_img.scaled(45, 45, Qt::KeepAspectRatio);
    chicken_img = chicken_img.scaled(45, 45, Qt::KeepAspectRatio);
    
    painter.drawImage(s_cow->getPosition()->getXpos() - 20,
                      s_cow->getPosition()->getYpos() - 25, cow_img);
    painter.drawImage(s_chicken->getPosition()->getXpos() - 20,
                      s_chicken->getPosition()->getYpos() - 25, chicken_img);
    
    painter.setPen(Qt::white);
    QString stateText;
    switch (s_cow->getState()) {
        case StateEnum::CowChasing:
            stateText = "Cow is chasing the chicken";
            break;
        case StateEnum::CowWander:
            stateText = "Cow is wandering in the field";
            break;
        default:
            stateText = "No idea";
            break;
    }
    painter.drawText(20, this->height() - 20, stateText);
}

MainWindow::~MainWindow()
{
    
}