#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Tablica {

private:
    int *tablica=new int[10]; //tablica
    int licznik=0;


public:
    int dodajElementy(int liczba){  //funkcja zwiekszajaca ilosc elementow i wypelniajaca tablice
	if(licznik<10) {
        tablica[licznik]=liczba; //wypelnienie nowej tablicy zerami
	licznik++;
	}
	else {
	int *tablicapomocnicza = new int[licznik+1];
        for (int i=0; i<licznik-1; i++) {
        tablicapomocnicza[i]=tablica[i];
         }
    tablicapomocnicza[licznik]=liczba;
	delete [] tablica;
	tablica=new int[licznik+1];
	for (int i=0; i<licznik; i++) {
	tablica[i]=tablicapomocnicza[i];
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
tablica.dodajElementy(0);
//tablica.dodajElementy(ile);
stop=clock(); //czas koncowy
tablica.zwolnijPamiec();

czas= (double)(stop-start) /CLOCKS_PER_SEC; //roznica koncowego czasu od czasu poczatkowego w sekundach
cout<<"Czas zwiekszania tablicy: "<<czas<<"[s]"<<endl;
return 0;

}
