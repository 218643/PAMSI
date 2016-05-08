#pragma once
#include "element.hh"
#include "node.hh"

/*!
* \brief Definicja klasy tree
* W tym pliku zdefiniowane są funkcje drzewa czerwono czarnego wedlug ponizszych zalozen:
*
*  Każdy węzeł drzewa jest albo czerwony, albo czarny.
*  Każdy liść drzewa (węzeł pusty nil) jest zawsze czarny.
*  Korzeń drzewa jest zawsze czarny.
*  Jeśli węzeł jest czerwony, to obaj jego synowie są czarni – innymi słowy, w drzewie nie mogą występować dwa kolejne czerwone węzły, ojciec i syn.
*  Każda prosta ścieżka od danego węzła do dowolnego z jego liści potomnych zawiera tę samą liczbę węzłów czarnych.
*/


class tree
{
  node* root; //referencja do zmiennej ktora przechowuje wskazanie korzenia drzewa
  node S;//straznik drzewa, ktory reprezentuje liscie;
public:
  tree(){S.black=1;S.up=&S;S.left=&S;S.right=&S;root=&S;}

/*!
* Dodaje kolejny element do struktury drzewa.
* Tworzy wezel, inicjujemy go danymi po czym wstawiamy go do drzewa za pomoca zwyklej procedury wstawiania wezla drzewa
* binarnego. Gdy wezel znajdzie sie w drzeie kolorujemy go na czerwono i sprawdzamy czy zostaly zachowane warunki.
* Jesli nowy wezel jest korzeniem to zmieniamy jego kolor na czarny. Jesli ojciec nowego wezla jest czarny to rowniez konczymy wstawianie
* poniewaz warunki zostalyz achowane.
* W przeciwnym razie mamy 3 przypadki ktore wystepuja w dwoch lustrzanych postaciach(zaznaczone w pliku tree.cpp)
*/
  int add(element el);

/*!
* Funkcja przeszukania drzewa.
* Wyszukuje wezel o kluczu k
* Jesli wezel nie zostanie znaleziony to wraca NULL
*/
  node* find(int key);

/*!
* Rotacja w lewo.
* Wykonuje rotacje w lewo wzgledem A
*
*/
  void leftRotate(node *A);

/*!
* Rotacja w prawo
* Wykonuje rotacje w prawo wzgledem A
*
*/
  void rightRotate(node *A);
};
