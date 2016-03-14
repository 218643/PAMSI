#pragma once


class IStos
{
    public:
    virtual void push() = 0; //umieszczenie na szczycie stosu
    virtual void pop() = 0; //zdjecie ze szczytu stosu
    virtual double Empty() = 0; // informacja czy stos jest pusty
    virtual void Size2() = 0; //zwraca ilosc elementow umieszczonych na stosie
    virtual bool top() = 0; //zwraca wartosc szczytowego elementu stosu

};

