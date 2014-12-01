//
//  MainWindow.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__MainWindow__
#define __Week1__MainWindow__

#include <Qt>
#include <QKeyEvent>
#include <QMainWindow>
#include <QObject>

#include "Graph.h"
#include "StateEnum.h"

class MainController;

class MainWindow : public QWidget
{
 Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    
    void setController(MainController* controller);
    void setGraph(std::shared_ptr<Graph> graph);
    void setUnits(std::shared_ptr<Cow> cow, std::shared_ptr<Chicken> chicken);
    
protected:
    virtual void keyPressEvent(QKeyEvent* key);
    virtual void paintEvent(QPaintEvent* event);
    
private:
    MainController* controller;
    std::shared_ptr<Graph> graph;
    
    std::weak_ptr<Cow> cow;
    std::weak_ptr<Chicken> chicken;
};

#endif /* defined(__Week1__MainWindow__) */
