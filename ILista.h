#pragma once

#include <string>

class ILista
{
    public:
    virtual void Add() = 0; //dodawanie elemntow
    virtual void Remove() = 0; //usuwanie elementow
    virtual double IsEmpty() = 0; //sprawdzanie czy pusta
    virtual void Get() = 0; //pobiera elemento z listy
    virtual void Size() = 0; //wyswietla rozmiar listy
    virtual bool prepare() = 0; //funkcja z IRunnable.h
    virtual bool run() = 0; //funckja z IRunnable.h
};
