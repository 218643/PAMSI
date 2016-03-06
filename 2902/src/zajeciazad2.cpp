#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

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

clock_t start, stop; //zmienne potrzebne do licznei aczasu
double czas;


Tablica tablica;
int ile;

cout<<"Podaj ile elementow wczytac"<<endl;
cin>>ile;
start=clock(); //czas poczatkowy
for(int i=0; i<ile; i++)
tablica.dodajElementy(ile,0);
stop=clock(); //czas koncowy
tablica.zwolnijPamiec();

czas= (double)(stop-start) /CLOCKS_PER_SEC; //roznica koncowego czasu od czasu poczatkowego w sekundach
cout<<"Czas zwiekszania tablicy: "<<czas<<"[s]"<<endl;
return 0;

}
