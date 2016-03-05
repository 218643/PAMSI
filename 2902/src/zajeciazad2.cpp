#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Tablica {
private:
    int *tablica; //tablica
    int *tablica2; //potrzebna do przepisania danych ze starej do nowej tablicy
    int rozmiar;
public:
    int dodajElementy(int ile){  //funkcja zwiekszajaca ilosc elementow i wypelniajaca tablice
        tablica= new int [ile];
        for (int i=0;i<ile;i++)
        tablica[i]=0;


        tablica2= new int[rozmiar];
        for (int i=0; i<rozmiar;i++)
        tablica2[i]=0;
        return 0;}



    void zwolnijPamiec(){ //zwolnienie pamieci
        delete [] tablica;
        delete [] tablica2;
        }

};



int main()
{

clock_t start, stop; //zmienne potrzebne do licznei aczasu
double czas;


Tablica tablica;
Tablica tablica2;
int ile;
int rozmiar;
cout<<"Podaj ile elementow wczytac"<<endl;
cin>>ile;
start=clock(); //czas poczatkowy
tablica.dodajElementy(ile);
tablica2.dodajElementy(rozmiar);
stop=clock(); //czas koncowy
tablica2.zwolnijPamiec();


czas= (double)(stop-start)/CLOCKS_PER_SEC; //roznica koncowego czasu od czasu poczatkowego.
cout<<"Czas zapisu(przy zwiekszaniu razy dwa) :"<<czas<<"[ms]"<<endl;
cout<<"rozmiar:"<<rozmiar;
return 0;

}
