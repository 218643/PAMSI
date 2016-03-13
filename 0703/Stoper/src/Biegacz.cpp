#include "Biegacz.h"

Biegacz::Biegacz()
{
//stworzenie tablicy do powiekszenia
    tablica = new int[poczatkowy_rozmiar_tablicy];
    rozmiar = poczatkowy_rozmiar_tablicy;
}

Biegacz::~Biegacz()
{
    delete [] tablica;
}
//Sprawdzamy czy tablica ma miejsce
bool Biegacz::czy_miejsce()
{
    return ilosc_elementow < rozmiar;
}
//Funckja dodaje element do tablicy.
void Biegacz::dodaj_element()
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

void Biegacz::zwieksz_tablice()
{
//funckja zwiekszajaca tablice o jeden lub razy dwa
   //int* nowa_tablica = new int[rozmiar+1];  //powiekszanie o jeden
   int* nowa_tablica = new int[rozmiar*2]; //pwoiekszanie razy dwa
   for(int i = 0; i < rozmiar; i++)
     nowa_tablica[i] = tablica[i];
   rozmiar=rozmiar*2;
//rozmiar++;  //dla zwiekszania o jeden.
   int* tymczasowy_wskaznik = tablica;
   tablica = nowa_tablica;

   delete [] tymczasowy_wskaznik;
}
//przygotowanie biegacza, czyli oczyszczenie z tablicy wynikow po wczesniejszym biegu i przygotowanie nowego dystansu.
bool Biegacz::prepare(int rozmiar_docelowy)
{
///Sprzatam po poprzednim "biegu", ustawiam wartosci poczatkowe
    delete [] tablica;
    tablica = new int[poczatkowy_rozmiar_tablicy];
    rozmiar = poczatkowy_rozmiar_tablicy;
    ilosc_elementow = 0;
    ostateczny_rozmiar = rozmiar_docelowy;///oczekiwana wart: 10,10^3,10^5...
    return true;
}

bool Biegacz::run()
{
//uzupelnianie tablicy zerami.
    for(int i = 0; i < ostateczny_rozmiar; i++)
        dodaj_element();
    return true;
}
