#include "graphsearch.hh"
#include <iostream>


bool graphSearch::DFS(int x)
{
  visited[x]=true;
  S.add(x,1);
  if(x==vk) return true;

  List p=sgraph.getNeighbors(x);

  for(int i=1;i<p.size()+1;i++)
    if(!visited[p.get(i)] && DFS(p.get(i)))
      return true;
  S.remove(1);
  return false;
}

void graphSearch::BFS(int x)
{
  S.add(x,1);
  visited[x]=true;

  while(S.size())
    {
      x=S.get(S.size());
      S.remove(S.size());


      List p=getNeighbors(x);
      for(int i=1;i<p.size()+1;i++)
	if(!visited[p.get(i)])
	  {
	    S.add(p.get(i),1);
	    visited[p.get(i)]=true;
	  }
    }
}
void graphSearch::findPathDFS(int x, int y)
{
  vk=y;
  for(int i=0;i<1000001;i++)
    visited[i]=0;

  if(!DFS(x))
    std::cout<<"BRAK"<<std::endl;
  else
    while(S.size())
      {

	S.remove(1);
      }
}

void graphSearch::findPathBFS(int x, int y)
{
  bool found;
  int v,u;
  int* P=new int[1000001];
  for(int i=0;i<1000001;i++)
    visited[i]=0;

  P[x]=-1;
  S.add(x,1);
  visited[x]=true;
  found=false;

  while(S.size())
    {
      v=S.get(S.size());
      S.remove(S.size());
      if(v==y)
	{
	  found=true;
	  break;
	}
      //sprawdzamy sasiedztwo v
      List p=sgraph.getNeighbors(v);
      for(int i=1;i<p.size()+1;i++)
	{
	  u=p.get(i);
	  if(!visited[u])
	    {
	      P[u]=v;
	      S.add(u,1);
	      visited[u]=true;
	    }
	}
    }
  if(!found)
    std::cout<<"BRAK"<<std::endl;
  else
    while(v>-1)
      {

	v=P[v];
      }
  delete[] P;
}
