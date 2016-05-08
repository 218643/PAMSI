#pragma once

#include "igraph.hh"
#include "lista.hh"



/*!
* \brief Definicja klasy graphSearch
* Klasa zawiera definicje zmiennych potrzebnych do stworzenia struktury grafu,
* Podstawowe funkcje tworzenia grafu oraz wyswietlanie sasiadów, rozmiaru grafu.
*
*/

class graph : public igraph
{
  List A[1000001];//macierz sasiedztwa
  int size;
public:
  graph(){size=0;}
  void addVertex(int);
  void addEdge(int,int);

/*!
* Wyswietla sąsiada/wiercholek lub informacje o nie istniejacym sąsiedzie/wierzcholku.
*
*/
  List getNeighbors(int);

/*!
* Opis metody w pliku graphsearch.hh
*
*/
  bool isConnected(int,int);


/*!
* Zwraca rozmiar naszego grafu.
*
*/
  int getsize();
};
