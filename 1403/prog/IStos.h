#pragma once
#include "Stos.h"


class IStos
{
    public:
    virtual void push(napis, 0) = 0; //umieszczenie na szczycie stosu
    virtual void pop(0) = 0; //zdjecie ze szczytu stosu
    virtual void empty() = 0; // informacja czy stos jest pusty
    virtual void size() = 0; //zwraca ilosc elementow umieszczonych na stosie
    virtual std::string top(0) = 0; //zwraca wartosc szczytowego elementu stosu

};

