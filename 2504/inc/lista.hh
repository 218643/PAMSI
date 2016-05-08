#pragma once
#include "node.hh"


class InterfaceList
{
public:
  virtual int add(int element, int position)=0;
  virtual void remove(int position)=0;
  virtual int get(int position)=0;
  virtual int size()=0;
};


/*!
*  Definicja klasy List
* Lista jest to lista sąsiedztwa. Przechowuje informacje czy dany element byl juz odwiedzony oraz jego pozycje.
* Klasa tworzy strukture listy, zawiera w sobie funckje dodawania elemntow do listy, sprawdzania czy lista jest pusta,
* usuwania elementow oraz zwracania rozmiaru naszej listy.
*
*/
class List : public InterfaceList
{
public:
  int Size;
  node* head;
  node* temp;
  node* temp2;
  List();
  int add(int element, int position);
  void remove(int position);
  int get(int position);
  int size();
};

