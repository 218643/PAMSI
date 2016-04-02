#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>

using namespace std;

class Tablica {

private:
    int *tablica=new int[10]; //tablica
    int licznik=0; //ilosc miejsc w tablicy


public:
//funkcja wypelnia tablice do momentu osiagniecia 10 elementow, nastepnie wykonuje else zwiekszajac jej rozmiar o jeden
//ponownie wypelnia elementy ifem i znow zwieksza o jeden w else.

                  float dodajElementy2(int rozmiar, int liczba)
            {
                if(rozmiar<10) //wypełnienie 10 elementow
                { //licznik zwieksza wartosc dopoki nie dosiegnie okreslonej wartosci, wtedy wykonuje else
                    for (int i = 0; i < 10; i++)
                        tablica[licznik]=liczba;
                }
                else
                {
                    int nowyRozmiar = licznik;
                    if (nowyRozmiar < rozmiar) //jesli ilsoc miejsc w tablicy jest mniejsza od ilosci elementow to zwieksza o jeden.
                    {
                        nowyRozmiar += nowyRozmiar+1;

                    }
                    int *NowaTablica = new int[nowyRozmiar]; // tworzy nowa tablice do ktorej wpisuje nowy rozmiar
                    for(int i = 0; i < nowyRozmiar; i++) //
                    {
                        NowaTablica[i] = liczba;

                    }
                }
            }
    void zwolnijPamiec(){ //zwolnienie pamieci
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
tablica.dodajElementy2(ile,1);
    gettimeofday(tim, NULL);
    double t2=tim->tv_sec+(tim->tv_usec/1000000.0);
cout << "Czas powiekszenia tablicy wynosi:"<<("%.6lf seconds elapsed\n", t2-t1)<<endl;
 return 0;
 }
