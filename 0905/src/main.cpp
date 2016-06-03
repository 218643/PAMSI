
#include <cstdlib>
#include "graph.hh"
#include "timer.hh"
#include <cstdlib>
#include <iostream>

int main(int Argc, char* Argv[]) {

srand(time(NULL));
graph* graph1 = NULL;
Stoper stoper;
int number_of_vertices[4]={10,100,1000,10000};

for(int i=0; i<4; i++) {

    graph1 = new graph(number_of_vertices[i]);

    for(int j=1; j<=(number_of_vertices[i]/2); j++) {
        if(j==1)
        graph1->add_edge(j, j*2, rand());
        else {
        graph1->add_edge(j, j*2, rand());
        graph1->add_edge(j, (j*2)-1, rand());
        }
    }

    for(int j=number_of_vertices[i]; j>3; j--)
        graph1->add_edge(j, j-1, rand());


    stoper.Start();
    graph1->BBsearch(number_of_vertices[i]/2);
    stoper.Stop();

    std::cout<<"Czas wyszukania Branch and Bound dla grafu "<<number_of_vertices[i]<<" elementowego wynosi: "<<stoper.getElapsedTime()<<"ms."<<std::endl<<std::endl;

    stoper.Start();
    graph1->BBsearch_with_extended_list(number_of_vertices[i]/2);
    stoper.Stop();

    std::cout<<"Czas wyszukania B&B with extended list dla grafu "<<number_of_vertices[i]<<" elementowego wynosi: "<<stoper.getElapsedTime()<<"ms."<<std::endl<<std::endl;

    delete graph1;

}



return 0;
}
