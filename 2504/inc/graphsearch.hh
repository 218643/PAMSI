#pragma once

#include "graph.hh"
#include "lista.hh"



/*!
* \brief Definicja klasy graphSearch
* Klasa ta zawiera w sobie funkcje odpowiedzialne za przeszukanie grafu, dodanie krawedzi i wierzcholkow
* oraz sprawdza czy kolejne wierzchołki są ze sobą połączone.
*
*
*/
class graphSearch
{
  graph sgraph;
  bool visited[1000001];
  List S;
  int vk;
public:

/*!
*   Sprawdza czy dane wierzchołki na odpowiednim poziomie były odwiedzone, sprawdza czy jest połączenie między kolejnymi wierzchołkami grafu.
*   Szuka ściezki między wierzchołkami.
*
*/
  void findPathBFS(int,int);

/*!
*   Algorytm sprawdza w odpowiedniej kolejności czy dany wierzchołek był odwiedzony oraz szuka ścieżki między wierzchołkami.
*
*/
  void findPathDFS(int,int);


/*!
* Rekurencyjny algorytm przeszukania grafu w głąb. Algorytm rozpoczyna przeszukanie grafu
* od wierzchołka o numerze 0.
*
*/
  bool DFS(int);


/*!
* Zaczynamy odwiedzanie od wierzchołka startowego. Następnie odwiedzamy wszystkich jego sąsiadów.
* Dalej odwiedzamy wszystkich nieodwiedzonych jeszcze sąsiadów sąsiadów. Itd. Aby uniknąć zapętlenia
* użyta zostala zmienna visited[] ktora okresla stan odwiedzin wierzcholka. Parametry te sa zebrane w tavblicy logicznej
* ktora posiada tyle elemntow ile wierzcholkow w grafie.
*
*/
  void BFS(int);


/*!
* Funkcja odpowiedzialna za dodawanie wierzchołków do grafu.
* Liczba wierzchołków zależna jest od liczby elementów podanych w pliku głównym.
*
*/
  void addVertex(int x)
  {
    sgraph.addVertex(x);
  }


/*!
* Funkcja jest odpowiedzialna za dodawanie krawędzi
* do umieszczonych w grafie wierzchołków startowy-końcowy.
*
*/
  void addEdge(int x,int y)
  {
    sgraph.addEdge(x,y);
  }
  List getNeighbors(int x)
  {
    return sgraph.getNeighbors(x);
  }


/*!
* Funkcja sprawdza połączenie między kolejnymi wierzchołkami
* Sprawdza relacje pomiędzy wierzchołkami.
*
*/
  bool isConnected(int x, int y)
  {
    return sgraph.isConnected(x,y);
  }

};

