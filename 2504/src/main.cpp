#include <iostream>
#include "graphsearch.hh"
#include "stoper.hh"
#include <cstdlib>

using namespace std;

int main()
{
  int X=1000;
  Stoper pomiar;
  graphSearch *graf=new graphSearch;

  cout<<"Ustawianie wierzcholkow"<<endl;
  for(int i=0;i<X;i++)
    graf->addVertex(i);

  cout<<"Ustawianie krawedzi"<<endl;
  for(int i=0;i<X;i++)
    graf->addEdge(i,i+1);
  graf->addEdge(0,X-1);
  cout<<"Dodawanie losowych krawedzi, ktore stanowia 10% z liczby wierzcholkow"<<endl;
  for(int i=0;i<(X/10);i++)
    graf->addEdge(rand()%X,rand()%X);

  pomiar.Start();
  graf->findPathBFS(0,rand()%X);
  pomiar.Stop();
  cout<<"BFS :"<< pomiar.getElapsedTime() <<endl;


  pomiar.Start();
  graf->findPathDFS(0,rand()%X);
  pomiar.Stop();
  cout<<"DFS :"<<pomiar.getElapsedTime() <<endl;

}
