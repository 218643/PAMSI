#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Tablica {

private:
    int *tablica=new int[10]; //tablica
    int licznik=0; //ilosc miejsc w tablicy
    int licznik2=0; //ilosc miejsc w tablicy pomocniczej


public:

//Funkcja w ifie wypelnia tablice do 10, nastepnie wykonuje else i mnozy miejsca tablicy razy dwa;
//nastepnie ponownie w ifie wypelnia do 20 uzupelniajac elmentami i ponownie w else mnozy razy dwa 40,80,160...

    int dodajElementy(int liczba){ //funkcja zwiekszajaca ilosc elementow i wypelniajaca tablice
        if(licznik<10+licznik2) { //licznik zwieksza wartosc dopoki nie dosiegnie okreslonej wartosci, wtedy wykonuje else
            tablica[licznik]=liczba;
            licznik++;
            }
        else {
            int *tablicapomocnicza = new int[licznik*2]; //utworzenie nowej tablicy, zwiekszenie jej rozmiaru razy dwa wzgledem wczesniejszego.
            for (int i=0; i<licznik-1; i++) {
            tablicapomocnicza[i]=tablica[i];
                    }
            licznik2=licznik2+licznik;
            licznik++;
            tablicapomocnicza[licznik]=liczba;
            delete [] tablica; //zwolnienie pamieci
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
stop=clock(); //czas koncowy
tablica.zwolnijPamiec();

czas= (double)(stop-start) /CLOCKS_PER_SEC; //roznica koncowego czasu od czasu poczatkowego w sekundach
cout<<"Czas zwiekszania tablicy: "<<czas<<"[s]"<<endl;
return 0;

}

