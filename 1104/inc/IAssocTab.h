#pragma once

#include <string>

class IAssocTab
{
    public:
    virtual int &operator [] (const char *) = 0;
    virtual void ArrayTab (int *tablica, int n) = 0;
    virtual void direct_search(int k) = 0;
    virtual void direct_insert(int x, int k) = 0;
    virtual void key(std::string k, int v) = 0;
};
