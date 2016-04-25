#pragma once

#include <string>


class Graf
{
public:
    virtual int array_size() = 0; ///tablica z rozmiarem.

    virtual void generate_Int(int gen) = 0; ///generuje losowe liczby.

    virtual void add_vertex(x) = 0; ///dodaje wierzchołek.

    virtual void add_edge (x,y,w=1) = 0; ///dodaje krawędz, waga domyslnie =1.

    virtual void remove_vertex(x,y) = 0; ///usuwa wierzchołek.

    virtual void get_neighbours(x) = 0; /// pobiera sąsiednie wierzchołki krawędzi x.

    virtual void BFS() = 0;

    virtual void DFS() = 0;

};
