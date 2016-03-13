#include <iostream>

#include "Sedzia.h"
#include "Biegacz.h"
#include "Stoper.h"

using namespace std;

int main()
{

//wywołanie funkcji
    Biegacz biegacz;
    Stoper stoper;
    Sedzia sedzia(biegacz, stoper);

    sedzia.release();
}
