#include "AssocTab.h"

int AssocTab::hash(std::string const& stringToHash)
{
  std::locale locale; // potrzebne konwersji na duze litery
  auto pierwszaLiteraZamienionaNaDuza = std::toupper(stringToHash[0],locale);
  int ascii = int(pierwszaLiteraZamienionaNaDuza);
  return ascii - 65;
}

NumerZWlascicielem AssocTab::direct_search(std::string wlasciciel)
{
  int indexListy = hash(wlasciciel);
  // zrobic hash z wlasciciela
  for(int i = 0; i < tab[indexListy].Size() + 1; i++)
  {
    // jezeli znajdziesz klucz, zwroc telefon z wlascicielem
    if(tab[indexListy].Get(i).wlasciciel == wlasciciel)
      return tab[indexListy].Get(i);
  }
  // jezeli nie znajdzie
  return NumerZWlascicielem("Nie znaleziono!",0);
}

void AssocTab::direct_insert(NumerZWlascicielem element)
{
  int index = hash(element.wlasciciel);
  tab[index].Add(element,tab[index].Size());
}
