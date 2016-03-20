#pragma once

#include "IRunnable.h"

const int poczatkowy_rozmiar_tablicy = 10;

class Biegacz :public IRunnable
{
    int *tablica;
    int rozmiar;
    int ilosc_elementow;
    int ostateczny_rozmiar;

    bool czy_miejsce();
    void dodaj_element();
    void zwieksz_tablice();

    public:
        Biegacz();
        virtual ~Biegacz();

        bool prepare(int size);
        bool run();
};
