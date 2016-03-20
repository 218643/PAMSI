#pragma once

#include <string>

class ILista
{
    public:
    virtual void Add(std::string item, int index) = 0; //dodawanie elemntow
    virtual void Remove(int index) = 0; //usuwanie elementow
    virtual bool IsEmpty() = 0; //sprawdzanie czy pusta
    virtual std::string Get(int index) = 0; //pobiera elemento z listy
    virtual int Size() = 0; //wyswietla rozmiar listy

};
