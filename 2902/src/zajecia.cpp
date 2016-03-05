#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Tablica {
private:
    int *tablica; //tablica

public:
    int dodajElementy(int ile){  //funkcja zwiekszajaca ilosc elementow i wypelniajaca tablice
        tablica= new int [ile];
        for (int i=0;i<ile;i++)
        tablica[i]=0; //wypelnienie nowej tablicy zerami
        return 0;
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
tablica.dodajElementy(ile);
stop=clock(); //czas koncowy
tablica.zwolnijPamiec();

czas= (double)(stop-start) /CLOCKS_PER_SEC; //roznica koncowego czasu od czasu poczatkowego w sekundach
cout<<"Czas zwiekszania tablicy: "<<czas<<"[s]"<<endl;
return 0;

}
