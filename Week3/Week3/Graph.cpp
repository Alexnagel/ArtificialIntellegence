//
//  Graph.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Graph.h"
#include "Cow.h"

Graph::Graph(MainWindow* p_main)
{
    main = p_main;
}

Graph::Graph(const Graph& rvalue): chicken(rvalue.chicken), vertices(rvalue.vertices), cameFrom(rvalue.cameFrom)
{
    
}

std::shared_ptr<Vertex> Graph::addVertex(int xpos, int ypos, bool isWall, bool hasPill)
{
    std::shared_ptr<Vertex> vertex = std::make_shared<Vertex>(xpos, ypos, isWall, hasPill);
    return vertex;
}

void Graph::addEdge(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to)
{
    int weight = 5;
    from->addEdge(to, weight);
}

void Graph::addEdges(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to)
{
    int weight = 5;
    from->addEdges(to, weight);
}

void Graph::addEdges(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to, int weight)
{
    from->addEdges(to, weight);
}

void Graph::setVertices(std::shared_ptr<std::vector<std::vector<std::shared_ptr<Vertex>>>> p_vertices)
{
    vertices = p_vertices;
}

std::vector<std::vector<std::shared_ptr<Vertex>>> Graph::getVertices()
{
    return *vertices;
}

int Graph::getWidth()
{
    return vertices->at(0).size();
}

int Graph::getHeight()
{
    return vertices->size();
}

void Graph::setUnits(std::shared_ptr<Chicken> p_chicken)
{
    chicken = p_chicken;
}

std::vector<std::shared_ptr<Vertex>> Graph::getRouteChicken(std::shared_ptr<Vertex> start)
{
    return getRoute(start, chicken->getPosition());
}

std::shared_ptr<Vertex> Graph::getRandomVertex()
{
    std::shared_ptr<Vertex> end;
    do{
        int x = Utils::randomNumber(getWidth() - 1);
        int y = Utils::randomNumber(getHeight() - 1);
        
        end = std::shared_ptr<Vertex>(vertices->at(y).at(x));
    }
    while (end->isWall());
    return end;
}

std::vector<std::shared_ptr<Vertex>> Graph::getRouteRandom(std::shared_ptr<Vertex> start)
{
    std::shared_ptr<Vertex> end = getRandomVertex();
    return getRoute(start, end);
}

std::vector<std::shared_ptr<Vertex>> Graph::getRoute(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
    cameFrom = new std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>>();
    std::map<std::shared_ptr<Vertex>, int> costSoFar;
    
    PriorityQueue queue;
    queue.put(start, 0);
    
    cameFrom->insert(std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>>(start, start));
    costSoFar[start] = 0;
    
    while (!queue.empty())
    {
        std::shared_ptr<Vertex> currentNode = queue.get();
        
        if (currentNode == end)
        {
            break;
        }

        for (std::shared_ptr<Edge> edge : currentNode->getEdges())
        {
            int cost = costSoFar[currentNode] + edge->getWeight();
            // If it doesn't contain this neighbour or the cost for this step is less than the existing step
            if (!costSoFar.count(edge->getDestination()) || cost < costSoFar[edge->getDestination()])
            {
                costSoFar[edge->getDestination()] = cost;
                
                // calculate priority for in the queue
                // add the total cost till this step with the heuristic
                int priority = cost + calculateHeuristic(edge->getDestination(), end);
                queue.put(edge->getDestination(), priority);
                // Add to the path map
                cameFrom->insert(std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>>(edge->getDestination(), currentNode));
            }
        }
        
        if (DEBUG_PATH)
        {
            main->setPaths(*cameFrom);
            main->repaint();
            qApp->processEvents();
        }
    }
    return createPath(start, end);
}

int Graph::calculateHeuristic(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
    // euclidean heuristic
    int dx = start->getXpos() - end->getXpos();
    int dy = start->getYpos() - end->getYpos();
    //return static_cast<int>(sqrt(dx*dx+dy*dy));
    
    // Manhattan
    return abs(dx) + abs(dy);
    
    // Chebyshev
    //return Utils::max(abs(dx), abs(dy));
}

std::vector<std::shared_ptr<Vertex>> Graph::createPath(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
    std::vector<std::shared_ptr<Vertex>> reconstruction;
    
    std::shared_ptr<Vertex> current = end;
    reconstruction.push_back(end);
    while (current != start)
    {
        current = (*cameFrom)[current];
        
        // don't push the start, not needed
        if (current != start)
            reconstruction.push_back(current);
    }
    delete cameFrom;
    
    // reverse vector because we pushed from end to start
    std::reverse(reconstruction.begin(),reconstruction.end());
    
    return reconstruction;
}

















