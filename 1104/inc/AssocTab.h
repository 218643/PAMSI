#pragma once
#include <string>
#include <iostream>

#include "IAssocTab.h"
#include "IHashTab.h"

class AssocTab : public IAssocTab
{
    int &operator [] (const char *);
    void ArrayTab (int *tablica, int n); ///inicjalizacja tablicy o rozmiarze zdefiniowanym w metodzie.
    void direct_search(int k); ///wyszukiwanie elementu o kluczu k.
    void direct_insert(int x, int k); ///dopisywanie elementu d o kluczu k
    void key(string k, int v); ///klucz



};
