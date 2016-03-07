#include "IRunnable.h"

class IRunnable
{
class Tablica {

private:
    int *tablica=new int[10]; //tablica
    int licznik=0; //ilosc miejsc w tablicy


public:

    virtual int prepare(int size); //mowi biegaczowi na jaka odleglosc biegnie.

    bool run();
}

