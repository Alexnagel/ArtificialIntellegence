//
//  MainWindow.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "MainWindow.h"
#include "MainController.h"

MainWindow::MainWindow(MainController* p_controller, QWidget *parent)
{
    controller = p_controller;
}

void MainWindow::setGraph(Graph p_graph)
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
    
    for (std::shared_ptr<Vertex> vertex : graph.getVertices())
    {
        painter.drawEllipse(vertex->getXpos() - 25, vertex->getYpos() - 25, 50, 50);
        painter.setPen(Qt::black);
        painter.drawText(vertex->getXpos(), vertex->getYpos() + 40, QString::fromStdString(std::to_string(vertex->getId())));
        
        for (std::shared_ptr<Edge> edge : vertex->getEdges())
        {
            painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
            painter.drawLine(edge->getOrigin()->getXpos(), edge->getOrigin()->getYpos(),
                             edge->getDestination()->getXpos(), edge->getDestination()->getYpos());
            
            int halfwayx = (edge->getOrigin()->getXpos() + edge->getDestination()->getXpos()) / 2;
            int halfwayy = (edge->getOrigin()->getYpos() + edge->getDestination()->getYpos()) / 2;
            painter.setPen(Qt::black);
            painter.drawText(halfwayx, halfwayy, QString::fromStdString(std::to_string(edge->getWeight())));
        }
        painter.setPen(Qt::darkGreen);
    }
    
    std::shared_ptr<Cow> s_cow = cow.lock();
    std::shared_ptr<Chicken> s_chicken = chicken.lock();
    QImage chicken_img(s_chicken->getImageURI());
    QImage cow_img(s_cow->getImageURI());
    
    cow_img = cow_img.scaled(45, 45, Qt::KeepAspectRatio);
    chicken_img = chicken_img.scaled(45, 45, Qt::KeepAspectRatio);
    
    painter.drawImage(s_cow->getPosition()->getXpos() - (cow_img.width() / 2),
                      s_cow->getPosition()->getYpos() - (cow_img.height() / 2), cow_img);
    painter.drawImage(s_chicken->getPosition()->getXpos() - (chicken_img.width() / 2),
                      s_chicken->getPosition()->getYpos() - (chicken_img.height() / 2), chicken_img);
}

MainWindow::~MainWindow()
{
    
}