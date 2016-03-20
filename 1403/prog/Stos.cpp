
#include "Stos.h"
#include "Lista.h"

class Stos: private Lista
{
void empty
{
    return Lista::IsEmpty();
}

std::string top
{
    if (Lista::IsEmpty)
        return "";
    else
        return Lista::Get(0);
}

void push(string napis)
    Lista::Add(napis, 0);

void pop()
{
    if(Lista::IsEmpty())
        cout<<"Brak elementow listy"<<endl;
    else
        Lista::Remove(0);
}

void size()
    return Lista::Size();

};
