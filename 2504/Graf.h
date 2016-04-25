#pragma once
#include <string>
#include <iostream>

#include "IGraf.h"

using namespace std;

class Graf
{

public:
    int array_size(); ///tablica z rozmiarem problemu.

    void generate_Int(int gen); ///generuje losowe liczby, które będą umieszczone na wierzchołki grafu.

    void add_vertex(x); ///dodaje wierzchołek.

    void add_edge (x,y,w=1); ///dodaje krawędz, waga domyslnie =1.

    void remove_vertex(x,y); ///usuwa wierzchołek.

    void get_neighbours(x); /// pobiera sąsiednie wierzchołki krawędzi x.

    void BFS(); ///algorytm szukania w szerz

    void DFS(); ///algorytm szukania w głąb

private:

    int V,E; ///liczba wierzchołków i krawędzi.
    int x,y; ///wierzchołek i krawędź.

};
