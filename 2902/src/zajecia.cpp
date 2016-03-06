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


public:
//funkcja wypelnia tablice do momentu osiagniecia 10 elementow, nastepnie wykonuje else zwiekszajac jej rozmiar o jeden
//ponownie wypelnia elementy ifem i znow zwieksza o jeden w else.
    int dodajElementy(int liczba){  //funkcja zwiekszajaca ilosc miejsc i wypelniajaca tablice
        if(licznik<10) { //mniejsze od 10 bo tablica ma poczatkowo 10 elmentow
            tablica[licznik]=0; //wypelnienie nowej tablicy zerami, jesli licznik<10 wstawia zera i zwieksza licznik.
            licznik++;
            }
        else {  //wykonuje else jesli licznik >10. Wtedy przepisuje stary rozmiar tablicy do nowej;
                //i zwiekszam ja ponownie aby pomiescila wczytywane elemmnty.
            int *tablicapomocnicza = new int[licznik+1];
            for (int i=0; i<licznik-1; i++) {
            tablicapomocnicza[i]=tablica[i];
            }
            tablicapomocnicza[licznik]=liczba;
            delete [] tablica; //zwolnienie pamieci
            tablica=new int[licznik+1];
            for (int i=0; i<licznik; i++) {
            tablica[i]=tablicapomocnicza[i];}
            licznik++;
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
