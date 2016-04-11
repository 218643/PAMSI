#pragma once

#include <string>


class AssocTab
{
    public:
    virtual int &operator [] (const char *);
    virtual void ArrayTab (int *tablica, int n);
    virtual void direct_search(int k);
    virtual void direct_insert(int x, int k);
    virtual void key(string k, int v);


};
