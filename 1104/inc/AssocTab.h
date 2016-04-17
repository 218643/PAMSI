#pragma once

#include "Lista.h"
#include "NumerZWlascicielem.h"

class AssocTab
{
 public:
  AssocTab(int n) :rozmiar(n) {} ///inicjalizacja tablicy o rozmiarze zdefiniowanym w metodzie. ( : mowi ze rozmiar zainicjalizuje n)
  NumerZWlascicielem direct_search(std::string wlasciciel); ///wyszukiwanie elementu o kluczu k.
  void direct_insert(NumerZWlascicielem element); ///dopisywanie elementu d o kluczu k
 private:
  int rozmiar;
  Lista<NumerZWlascicielem> tab[32];
  int hash(std::string const& stringToHash);
};
