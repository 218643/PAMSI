#include "graph.hh"


graph::graph(int wierzcholki) {

    sizeofneighbourslist = wierzcholki;
    neighbourslist = new List<int> [sizeofneighbourslist];

    costmatrix = new int* [sizeofneighbourslist];

    for(int i=0; i<sizeofneighbourslist; i++) {
        costmatrix[i] = new int [sizeofneighbourslist];
        for(int j=0; j<sizeofneighbourslist; j++)
            costmatrix[i][j]=0;
        }

}

graph::~graph() {

    delete []neighbourslist;

    for(int i=0; i<sizeofneighbourslist; i++)
    delete []costmatrix[i];

    delete []costmatrix;

}

void graph::add_vertex(const int& v) {

    if(v<=sizeofneighbourslist)
    std::cout<<"Istnieje już węzeł o podanym numerze. Graf zawiera "<<sizeofneighbourslist<<" wierzchołków."<<std::endl;

    List<int>* help = new List<int> [sizeofneighbourslist+1];

    for(int i=0; i<sizeofneighbourslist; i++)
        help[i]=neighbourslist[i];

    delete neighbourslist;

    sizeofneighbourslist++;

    neighbourslist = new List<int> [sizeofneighbourslist];

    for(int i=0; i<sizeofneighbourslist; i++)
        neighbourslist[i]=help[i];

    delete help;

}

void graph::add_edge(const int& x, const int& y, const int& cost) {

    neighbourslist[x-1].add(y-1, neighbourslist[x-1].size()+1);
    neighbourslist[y-1].add(x-1, neighbourslist[y-1].size()+1);

    costmatrix[x-1][y-1]=cost;

}

void graph::remove_vertex(const int& v) {


}

void graph::remove_edge(const int& x, const int& y) {


}

List<int> graph::get_neighbours(const int& v) {
    return neighbourslist[v];
}

bool graph::is_connected(const int& x, const int& y) {

    for(int i=0; i<neighbourslist[i].size(); i++)
        if(neighbourslist[i].at(i)==y)
            return true;

    return false;
}


void graph::BBsearch(const int& v) {

    PriorityQueue<int>* wierzcholki = new PriorityQueue<int>;
    PriorityQueue<int>* pathlengths = new PriorityQueue<int>;
    pathlengths->add(0,0);
    int numberofextendedpaths=0;
    int calatrasa=0;
    int minimalnatrasa=0;

    wierzcholki->add(0, costmatrix[0][0]); // zaczynamy od węzła startowego

    while(wierzcholki->size()!=0) { // zdejmujemy elementy z kolejki priorytetowej dopoki nie znajdziemy szukanego

        int elem=wierzcholki->remove();
        calatrasa=pathlengths->remove();
        if(elem==v) {
            std::cout<<"Znaleziono element!"<<std::endl;
            minimalnatrasa=calatrasa; // oznaczamy minimalna trase po znalezieniu elementu
            break;
            }



        for(int i=0; i<neighbourslist[elem].size(); i++) {
            int tmp_elem=neighbourslist[elem].at(i+1);
            numberofextendedpaths++;
            wierzcholki->add(tmp_elem, calatrasa+costmatrix[elem][tmp_elem]); // dodajemy sasiada do kolejki
            pathlengths->add(calatrasa+costmatrix[elem][tmp_elem],calatrasa+costmatrix[elem][tmp_elem]); // dodajemy dlugosc drogi do kolejki
            }

        }

    while(wierzcholki->size()!=0) { // szukamy innych sciezek biorac pod uwage elementy z kolejki

        int tmp_elem=wierzcholki->remove();
        calatrasa=pathlengths->remove();
        if(calatrasa>=minimalnatrasa) { // jesli sciezka jest wieksza niz minimalna, pomijamy element
            continue;
            }
        else if(tmp_elem!=v && calatrasa<minimalnatrasa) { // dodajemy sasiadow jezeli jest szansa na znalezienie krotszej sciezki
            for(int i=0; i<neighbourslist[tmp_elem].size(); i++) {
                int tmp_elem3=neighbourslist[tmp_elem].at(i+1);
                numberofextendedpaths++;
                wierzcholki->add(tmp_elem3, calatrasa+costmatrix[tmp_elem][tmp_elem3]); // dodajemy sasiada do kolejki
                pathlengths->add(calatrasa+costmatrix[tmp_elem][tmp_elem3],calatrasa+costmatrix[tmp_elem][tmp_elem3]); // dodajemy dlugosc drogi do kolejki
                }
            }

        else if(tmp_elem==v && calatrasa<minimalnatrasa) { //  zapisujemy nowa najkrotsza sciezke
            minimalnatrasa=calatrasa;
            std::cout<<"Znaleziono nową minimalną ścieżkę!"<<std::endl;
            }

        }

    std::cout<<"Liczba rozwiniętych sciezek: "<<numberofextendedpaths<<std::endl;


    delete wierzcholki;
    delete pathlengths;
}

void graph::BBsearch_with_extended_list(const int& v) {

    PriorityQueue<int>* wierzcholki = new PriorityQueue<int>;
    PriorityQueue<int>* pathlengths = new PriorityQueue<int>;
    visited = new int[sizeofneighbourslist];
    pathlengths->add(0,0);
    int numberofextendedpaths=0;
    int calatrasa=0;
    int minimalnatrasa=0;

    for(int i=0; i<sizeofneighbourslist; i++)
    visited[i]=0;

    wierzcholki->add(0, costmatrix[0][0]); // zaczynamy od węzła startowego

    while(wierzcholki->size()!=0) { // zdejmujemy elementy z kolejki priorytetowej dopoki nie znajdziemy szukanego

        int elem=wierzcholki->remove();
        calatrasa=pathlengths->remove();

        if(visited[elem]==0)
        visited[elem]=1; // oznaczamy odwiedzony wierzcholek

        if(elem==v) {
            std::cout<<"Znaleziono element!"<<std::endl;
            minimalnatrasa=calatrasa; // oznaczamy minimalna trase po znalezieniu elementu
            break;
            }



        for(int i=0; i<neighbourslist[elem].size(); i++) {
            int tmp_elem=neighbourslist[elem].at(i+1);
            if(visited[tmp_elem]==0) { // tylko jesli go jeszcze nie rozwinieto
                numberofextendedpaths++;
                wierzcholki->add(tmp_elem, calatrasa+costmatrix[elem][tmp_elem]); // dodajemy sasiadow do kolejki
                pathlengths->add(calatrasa+costmatrix[elem][tmp_elem],calatrasa+costmatrix[elem][tmp_elem]); // dodajemy droge do kolejki
                }
            }

        }

   while(wierzcholki->size()!=0) { // szukamy innych drog biorac pod uwage to co w kolejce

        int tmp_elem=wierzcholki->remove();
        calatrasa=pathlengths->remove();

        if(visited[tmp_elem]==0)
        visited[tmp_elem]=1; // oznaczamy odwiedzone wierzcholki
        if(calatrasa>=minimalnatrasa) {
            continue;
            }
        else if(tmp_elem!=v && calatrasa<minimalnatrasa) {
            for(int i=0; i<neighbourslist[tmp_elem].size(); i++) {
                int tmp_elem3=neighbourslist[tmp_elem].at(i+1);
                if(visited[tmp_elem3]==0) { // tylko jesli go jeszcze nie rozwinieto
                    numberofextendedpaths++;
                    wierzcholki->add(tmp_elem3, calatrasa+costmatrix[tmp_elem][tmp_elem3]); // dodajemy sasiadow do kolejki
                    pathlengths->add(calatrasa+costmatrix[tmp_elem][tmp_elem3],calatrasa+costmatrix[tmp_elem][tmp_elem3]); // dodajemy nasza droge do kolejki
                    }
                }
            }

        else if(tmp_elem==v && calatrasa<minimalnatrasa) { // zapisanie nowej najlepszej trasy po znalezieniu jej
            minimalnatrasa=calatrasa;
            std::cout<<"Znaleziono nową minimalną ścieżkę!"<<std::endl;
            }

        }

    std::cout<<"Liczba rozwiniętych sciezek: "<<numberofextendedpaths<<std::endl;


    delete wierzcholki;
    delete pathlengths;
    delete visited;


}
