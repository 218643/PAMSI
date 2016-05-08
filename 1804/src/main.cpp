#include <iostream>
#include "element.hh"
#include "stoper.hh"
#include "tree.hh"
#include <cstdlib>

using namespace std;

int main()
{
  const int sup=100000;// liczba elementow
  tree *drzewko;
  Stoper s;
  drzewko=new tree;
  element e1;
  s.Start();
  for(int i=0;i<sup;i++)
    {
      e1.key=rand();
      drzewko->add(e1);
    }
  s.Stop();
  std::cout <<"Czas budowania drzewa:"<< s.getElapsedTime() <<" ms"<< std::endl;
  s.Start();
  drzewko->find(e1.key);
  s.Stop();
std::cout <<"Czas wyszukania:"<< s.getElapsedTime() <<" ms"<< std::endl;
}
