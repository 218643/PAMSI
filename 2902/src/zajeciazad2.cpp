#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>

using namespace std;

class Tablica {

private:
    int *tablica=new int[10]; //tablica
    int licznik; //ilosc miejsc w tablicy
public:
/*Funkcja w ifie wypelnia tablice do 10, nastepnie wykonuje else i mnozy miejsca tablicy razy dwa;
nastepnie ponownie w ifie wypelnia do 20 uzupelniajac elmentami i ponownie w else mnozy razy dwa 40,80,160...*/

    float dodajElementy(int rozmiar, int liczba) //funkcja zwiekszajaca ilosc elementow i wypelniajaca tablice
            {
                if(rozmiar<10) //wypełnienie 10 elementow
                { //licznik zwieksza wartosc dopoki nie dosiegnie okreslonej wartosci, wtedy wykonuje else
                    for (int i = 0; i < 10; i++)
                        tablica[licznik]=liczba;
                }
                else
                {
                    int nowyRozmiar = licznik;
                    if (nowyRozmiar < rozmiar)
                    {
                        nowyRozmiar += nowyRozmiar*2; // zwiekszenie rozmiaru tablicy razy dwa

                    }
                    int *NowaTablica = new int[nowyRozmiar];
                    //delete [] tablica;
                    for(int i = 0; i < nowyRozmiar; i++)
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
tablica.dodajElementy(ile,0);
    gettimeofday(tim, NULL);
    double t2=tim->tv_sec+(tim->tv_usec/1000000.0);
cout << "Czas powiekszenia tablicy wynosi:"<<("%.6lf seconds elapsed\n", t2-t1)<<endl;
tablica.zwolnijPamiec();
 return 0;
 }
