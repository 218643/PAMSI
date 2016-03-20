#include "BiegaczLista.h"

bool BiegaczLista::prepare(int rozmiar_docelowy)
{
while(Lista::Size() !=0) ///sprztanie po poprzedniej liscie.
Lista::Remove(0);


for(int i=0; i<rozmiar_docelowy;i++)
  Lista::Add("random",i);///wypelnienie listy losowymi slowami/elementami(stale)

///wrzucanie wyrazu na losowe miejsce w liscie
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> uni(0,rozmiar_docelowy);

int random_integer = uni(rng);
Lista::Add("szukana",random_integer);
}

bool BiegaczLista::run()
{
///przeszukuje liste by znalezc slowo podane nizej.
  for (int i = 0; i < Lista::Size()+1; i++)
  if(Lista::Get(i) == "szukana" )
        return true;
return false;
}
