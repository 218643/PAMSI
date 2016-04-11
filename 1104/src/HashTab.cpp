#pragma once
#include <string>
#include <iostream>

#include "IHashTab.h"





  void hash(int hash_size) //konstruktor wypelnia tablice haszujaca pustymi listami (metoda lancuchowa)
     {
        hasz_size = n;
        hashSize = hash_size;
        hashTable = new ArrayList[hash_size];

        for (int i=0;i<hash_size;i++)
        {
            hashTable[i]=new ArrayList<String>();
        }
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
