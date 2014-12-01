//
//  Graph.cpp
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#include "Graph.h"

Graph::Graph()
{
    
}

std::shared_ptr<Vertex> Graph::addVertex(int xpos, int ypos, int _id)
{
    std::shared_ptr<Vertex> vertex = std::make_shared<Vertex>(xpos, ypos, _id);
    vertices.push_back(vertex);
    return vertex;
}

void Graph::addEdge(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to)
{
    int weight = Utils::randomNumber(100);
    from->addEdge(to, weight);
}

void Graph::addEdges(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to)
{
    int weight = Utils::randomNumber(100);
    from->addEdges(to, weight);
}

void Graph::addEdges(std::shared_ptr<Vertex> from, std::shared_ptr<Vertex> to, int weight)
{
    from->addEdges(to, weight);
}

std::vector<std::shared_ptr<Vertex>> Graph::getVertices()
{
    return vertices;
}

std::vector<std::shared_ptr<Vertex>> Graph::getRoute(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
    cameFrom = std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>>();
    std::map<std::shared_ptr<Vertex>, int> costSoFar;
    
    PriorityQueue queue;
    queue.put(start, 0);
    
    cameFrom[start] = start;
    costSoFar[start] = 0;
    
    while (!queue.empty())
    {
        std::shared_ptr<Vertex> currentNode = queue.get();
        
        if (currentNode == end)
            break;
        
        // init neighbours map containing the neighbours and their respective edge weights
        std::map<std::shared_ptr<Vertex>, int> neighbours;
        
        // get the edges for this vertex
        std::vector<std::shared_ptr<Edge>> edges = currentNode->getEdges();
        for (std::shared_ptr<Edge> edge : edges)
        {
            if (edge->getDestination() != currentNode)
                neighbours[edge->getDestination()] = edge->getWeight();
        }
        
        for (std::pair<std::shared_ptr<Vertex>,int> neighbour : neighbours)
        {
            int cost = costSoFar[currentNode] + neighbour.second;
            // If it doesn't contain this neighbour or the cost for this step is less than the existing step
            if (!costSoFar.count(neighbour.first) || cost < costSoFar[neighbour.first])
            {
                costSoFar[neighbour.first] = cost;
                
                // calculate priority for in the queue
                // add the total cost till this step with the heuristic
                int priority = cost + calculateHeuristic(neighbour.first, end);
                queue.put(neighbour.first, priority);
                // Add to the path map
                cameFrom[neighbour.first] = currentNode;
            }
        }
    }
    return createPath(start, end);
}

int Graph::calculateHeuristic(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
    // use absolute for when negative numbers occur
    //return abs(start->getXpos() - end->getXpos()) + abs(start->getYpos() - end->getYpos());
    //Euclidian heuristic
    int xd = start->getXpos() - end->getXpos();
    int yd = start->getYpos() - end->getYpos();
    return static_cast<int>(sqrt(xd*xd+yd*yd));
}

std::vector<std::shared_ptr<Vertex>> Graph::createPath(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
    std::vector<std::shared_ptr<Vertex>> reconstruction;
    
    std::shared_ptr<Vertex> current = end;
    reconstruction.push_back(end);
    while (current != start)
    {
        current = cameFrom[current];
        
        // don't push the start, not needed
        if (current != start)
            reconstruction.push_back(current);
    }
    
    // reverse vector because we pushed from end to start
    std::reverse(reconstruction.begin(),reconstruction.end());
    
    return reconstruction;
}

















