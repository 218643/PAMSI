#pragma once

#include <string>

class IKolejka
{
    public:
    virtual bool pop_back() = 0;  //dodaje nowy el na poczatke kolejki.
    virtual bool push_back() = 0; //dodaje nowy element na koneic kolejki
    virtual int first() = 0;   //odczyt i modyf. wartosci z poczatku kolejki.
    virtual int last(int) = 0; //sluzy do odczytania lub modyf. wartosci umieszczonej na koncu kolejki.
    virtual unsigned int Size() = 0;  //rozmiar kolejki.


};
