#include "Graf.h"




Graf::Graf()
{
V=0;
E=0;
}

int Graf::array_size()
{
int tablica (7)={10,100,1000,10000,100000,1000000,1000000000};
}


void Graf::generate_Int(int gen)
{
int a, b;
    a = 0;
    b = 900000;
std::ofstream plik("tekst.txt");
for(int i = 0; i < gen; i++)
    plik << a+(rand() % (b-a+1)) << endl;
}




void Graf::add_vertex ()
{
///dołącz wierzchołek na podaną pozycje
}


void Graf::add_edge ()
{
///dodaj krawędź po indeksach x i y
}

void Graf::remove_vertex()
{
///usun wierzchołek
}


void Graf::get_neighbours()
{
///pobierz sąsiednie wierzchołki krawędzi x
}

void Graf::BFS
{
1.Włóż do kolejki q wybrany wierzchołek grafu i zamarkuj go.
2. Dopóki kolejka  q nie jest pusta :
            Wez pierwszy element kolejki q.
            Dopisz  do kolejki wszystkie wierzchołki z nim incydentne, o ile nie były jeszcze zamarkowane i
            każdy z nich zamarkuj.
            Usuń pierwszy element kolejki q.
}

void Graf::DFS
{
1.Zaznacz wybrany wierzchołek jako odwiedzony.
2. Dla każdego wierzchołka z listy incydencji wybranego wierzchołka:
              Jeśli wierzchołek nie był jeszcze zamarkowany, to
              zastosuj rekurencyjnie procedurę odwiedzania do tego wierzchołka.
}
