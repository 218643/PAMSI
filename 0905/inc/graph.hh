
#pragma once
#include "igraph.hh"
#include "list.hh"
#include "queue.hh"
#include "priorityqueue.hh"

 /*!
* \brief Klasa grafu.
*
* Metody pracujace na grafie
*/
class graph : public Igraph {

private:
List<int>* neighbourslist = nullptr;
int **costmatrix = nullptr;
int sizeofneighbourslist = 0;
int* visited = nullptr;

public:

graph(int wierzcholki);
~graph();

/*
 * Metoda dodająca wierzchołek do grafu.
 * Dodaje wierzcholek po zainicjiwaniu grafu.
 *
 *
 *
 */
void add_vertex(const int& v);

/*
 * Metoda dodająca krawędź do grafu.
 *
 *
 */
void add_edge(const int& x, const int& y, const int &cost);

/*
 * Metoda usuwająca wierzchołek z grafu.
 *
 *
 *
 */
void remove_vertex(const int& v);

/*
 * Metoda usuwająca krawędź z grafu.
 *
 *
 */
void remove_edge(const int& x, const int& y);

/*
 * Metoda zwracająca listę sąsiadów danego wierzchołka.
 *
 */
List<int> get_neighbours(const int& v);

/*
 * Metoda sprawdzająca istnienie krawędzi pomiędzy dwoma wierzchołkami.
 *
 *
 *
 */
bool is_connected(const int& x, const int& y);



/*
 * Metoda przeszukująca graf wykorzystująca branch and bound
 *
 */
void BBsearch(const int &v);

/*
 * Metoda przeszukująca graf wykorzystująca branch and bound with extended list
 *
 *
 */
void BBsearch_with_extended_list(const int &v);


};
