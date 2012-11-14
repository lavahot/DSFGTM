//
//  Graph.h
//  project6
//
//  Created by Taylor Mansfield on 11/10/12.
//  Copyright (c) 2012 Taylor Mansfield. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <cstdlib>

class Edge
{
private:
    int weight;
    int index;
    Edge* next;
public:
    Edge()
    {
        index =0;
        weight = 0;
        next=NULL;
    }
    ~Edge();
    void setWeight(int w)
    {
        weight=w;
    }
    int getWeight()
    {
        return weight;
    }
    void setIndex(int i)
    {
        index=i;
    }
    
};

class Vertex
{
private:
    bool mark;
    Vertex* next;
    Edge* edge;
public:
    Vertex()
    {
        mark=false;
        next=NULL;
        edge=NULL;
    }
    ~Vertex()
    {}
};

class Graph
{
private:
    Vertex* start;
    int size;
public:
    Graph();
    ~Graph();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    
};

#endif /* defined(Graph) */
