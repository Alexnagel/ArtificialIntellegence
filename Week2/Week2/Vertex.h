//
//  Vertex.h
//  Week1
//
//  Created by Alex Nagelkerke on 29-11-14.
//  Copyright (c) 2014 Alex Nagelkerke. All rights reserved.
//

#ifndef __Week1__Vertex__
#define __Week1__Vertex__

#include <vector>
#include <memory>

class Edge;

class Vertex : public std::enable_shared_from_this<Vertex>{
public:
    Vertex(int xpos, int ypos, int p_id);
    Vertex(const Vertex& vertex);
    
    void addEdge(std::shared_ptr<Vertex> to, int weight);
    void addEdges(std::shared_ptr<Vertex> to, int weight);
    bool isVisited();
    void setVisited(bool isVisited);
    
    int getXpos();
    int getYpos();
    int getId();
    std::vector<std::shared_ptr<Edge>> getEdges();
private:
    bool visited;
    std::vector<std::shared_ptr<Edge>> edges;
    
    int xpos;
    int ypos;
    int _id;
};


#endif /* defined(__Week1__Vertex__) */
