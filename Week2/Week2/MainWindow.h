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
#include <QCloseEvent>


#include "StateEnum.h"

class MainController;
class Graph;
class Cow;
class Chicken;
class Vertex;

class MainWindow : public QWidget
{
 Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    
    void setController(MainController* controller);
    void setGraph(std::shared_ptr<Graph> graph);
    void setUnits(std::shared_ptr<Cow> cow, std::shared_ptr<Chicken> chicken);
    void closeEvent(QCloseEvent *event);
    
    void drawSearch();
    void setPaths(std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> paths);

protected:
    void paintEvent(QPaintEvent* event);
    
private:
    static const bool DRAW_COW_PATH = true;
    
    MainController* controller;
    std::shared_ptr<Graph> graph;
    std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> paths;
    
    std::weak_ptr<Cow> cow;
    std::weak_ptr<Chicken> chicken;
    
    // Draw functions
    void drawStateText();
    void drawUnits();
    void drawMap();
};

#endif /* defined(__Week1__MainWindow__) */
