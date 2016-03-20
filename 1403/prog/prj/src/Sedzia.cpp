#include "Sedzia.h"

void Sedzia::release()
{
    std::ifstream strumien_na_plik (NAZWA_PLIKU_Z_ILOSCIA_ELEMENTOW);
//wczytanie dystansu z pliku
    for(int ilosc_danych; strumien_na_plik >> ilosc_danych;) //przekazuje dystans z pliku na zmienna
    {
    _biegacz.prepare(ilosc_danych); //przygotowanie biegacza
    _stoper.Start(); //wystartowanie zegara
    _biegacz.run(); //pokananie dystansu przez biegacza
    _stoper.Stop(); //zastopowanie zegara

    std::cout <<"Wyniki kolejnych dystansów:"<< _stoper.getElapsedTime() << std::endl; //wystwietlenie i zapisanie do pliku wyniki czasów biegu.
    _stoper.dumpToFile("wyniki.txt");
    }
}
