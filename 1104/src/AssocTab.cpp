#pragma once
#include <string>
#include <iostream>

#include "IAssocTab.hh"


using namespace std;


///tutaj mamy od razu rozmiar naszej tablicy
   void ArrayTab (int *tablica, int n)
    {
        boost::array < int, 4 > tablica = { 1, 2, 3 };
        for( n_t i = 0; i < tablica.n(); ++i )

        return 0;
    }

    int & AssocTab::operator[] (const char *key)
    {
        node *c = find (key);

        if (!c)
        {
                insert (key, 0);
                c = head;
        };

        return c->val;
    }


   void direct_search(int k)
     {
       return array[k];
     }




    void direct_insert(int x, int k)
     {
        array[k] = x;
     }



    void key(string k, int v)//funckja klucza.
      {


      }
