#include "AssocTab.h"
#include "Stoper.h"
#include <iostream>
#include <fstream>


int main ()
{
  AssocTab tablicaAssoc(26);
  Stoper stoper;

  stoper.Start(); //wystartowanie zegara
  std::ifstream plik("kontakty.txt");
  for(NumerZWlascicielem numZWlas; plik >> numZWlas.wlasciciel >> numZWlas.numer_tel;)
  {
    tablicaAssoc.direct_insert(numZWlas);
  }
  stoper.Stop();
  std::cout <<"Czas uzupełniania tablicy:"<< stoper.getElapsedTime() << std::endl;

  stoper.Start();
  //NumerZWlascicielem numerZW("Kowalski",123456789);
  //tablicaAssoc.direct_insert(numerZW);
  auto znaleziony = tablicaAssoc.direct_search("Patryk");
 stoper.Stop();
  std::cout << znaleziony.wlasciciel << "" << znaleziony.numer_tel << std::endl;
  std::cout <<"Czas wyszukania nazwiska:"<< stoper.getElapsedTime() << std::endl; //wystwietlenie i zapisanie do pliku wyniki czasów biegu.
    stoper.dumpToFile("wyniki.txt");
}
