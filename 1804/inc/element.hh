#pragma once


/*!
*brief Definicja klasy element.
*Klasa pomocnicza utworzona do budowania struktury drzewa.
*Zmienna value przechowuje wygenerowane elementy
*Zmienna key jest zmienna pomocniczą wykorzystywana przy pozycjonowaniu elementow drzewa.
*Drzewo działa tak, że po lewej stronie umieszcza elementy(value) o mniejszej wartosci key.
*/

class element
{
public:
  int key;
  int value;
  element(){key=0;value=0;}
};
