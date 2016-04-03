#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>
//#include <chrono>

using namespace std;

class Tablica {

private:
    //int *tablica=new int[10]; //tablica
    int licznik=0; //ilosc miejsc w tablicy
    int *tablica;
    int rozmiar;
    int ilosc_elementow;
    int ostateczny_rozmiar;

public:
//funkcja wypelnia tablice do momentu osiagniecia 10 elementow, nastepnie wykonuje else zwiekszajac jej rozmiar o jeden
//ponownie wypelnia elementy ifem i znow zwieksza o jeden w else.

Tablica()
{
    delete [] tablica;
}
//Sprawdzamy czy tablica ma miejsce
bool czy_miejsce()
{
    return ilosc_elementow < rozmiar;
}
//Funckja dodaje element do tablicy.
void dodaj_element()
{
    if(czy_miejsce()) //sprawdza czy jest miejsce w talicy i uzupelnia ja elementami
    {
        tablica[ilosc_elementow] = 0;
        ilosc_elementow++;
    }
    else
    {
        zwieksz_tablice(); //jesli nie ma miejsca to powieksza tablice
        tablica[ilosc_elementow] = 0;
        ilosc_elementow++;
    }
}

void zwieksz_tablice()
{
//funckja zwiekszajaca tablice o jeden lub razy dwa
   int* nowa_tablica = new int[rozmiar+1];  //powiekszanie o jeden
   //int* nowa_tablica = new int[rozmiar*2]; //pwoiekszanie razy dwa
   for(int i = 0; i < rozmiar; i++)
     nowa_tablica[i] = tablica[i];
   //rozmiar=rozmiar*2;
    rozmiar++;  //dla zwiekszania o jeden.
   int* tymczasowy_wskaznik = tablica;
   tablica = nowa_tablica;

   delete [] tymczasowy_wskaznik;
}

bool run()
{
//uzupelnianie tablicy zerami.
    for(int i = 0; i < ostateczny_rozmiar; i++)
        dodaj_element();
    return true;
}
void clean()
{
delete [] tablica;
}
};


int main()
{
Tablica tablica;
int ile, i;
struct timeval *tim;
cout<<"Podaj ile elementow wczytac"<<endl;
cin>>ile;
    gettimeofday(tim, NULL);
    double t1=tim->tv_sec+(tim->tv_usec/1000000.0);
for(int i=0; i<ile; i++)
tablica.run();
    gettimeofday(tim, NULL);
    double t2=tim->tv_sec+(tim->tv_usec/1000000.0);
cout << "Czas powiekszenia tablicy wynosi:"<<("%.6lf seconds elapsed\n", t2-t1)<<endl;
tablica.clean();
 return 0;
 }
/*int main()
{
Tablica tablica;
int ile, i;
//struct timeval *tim;
using clock = std::chrono::high_resolution_clock;///czas systemowy
using time_point = clock::time_point;
using time_type = std::chrono::milliseconds;
cout<<"Podaj ile elementow wczytac"<<endl;
cin>>ile;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for(int i=0; i<ile; i++)
    tablica.run();
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "Wykonano w czasie: " << elapsed_seconds.count() << "s\n";
              return 0;
              }*/
