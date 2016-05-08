#pragma once
#include "lista.hh"

class igraph
{
public:
  virtual void addVertex(int v)=0;
  virtual void addEdge(int x, int y)=0;
  virtual List getNeighbors(int x)=0;
  virtual bool isConnected(int x, int y)=0;
};


