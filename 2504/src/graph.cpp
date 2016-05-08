#include "graph.hh"
#include <iostream>

 bool graph::isConnected(int x, int y)
  {
    if(x<size && y<size)
      {
    int z;
    z=0;
    for(int i=1;i<A[x].size()+1;i++)
      if(A[x].get(i)==y)
	z=1;
    if(z==1)
      return true;
    else
      return false;
      }
    else
      std::cout<<"przekroczenie w isConnected"<<std::endl;
  }

void graph::addVertex(int x)
{
  if(x>=size)
  size++;
  else
    std::cout<<"Taki wierzcholek juz istnieje(addVertex)"<<std::endl;
}

void graph::addEdge(int x, int y)
{
  A[x].add(y,1);
  A[y].add(x,1);
}

List graph::getNeighbors(int x)
{
  if(x<size+1)
  return A[x];
  else
    std::cout<<"taki wierzcholek nie istnieje(getNeighbors)"<<std::endl;
}
int graph::getsize()
{
  return size;
}
