#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>



using namespace std;

class Tablica;{

private:
    int *tablica;

public:
    void dodajElementy(int n) {
        tablica =new int [n];
        for (int i=0;i<n; i++){
        tablica[n]=rand();
        }
    }
    void zwolnijPamiec() {
        delete [] tablica;
        }
}

int main()
{
Tablica tablica;
int ile=10;
tablica.dodajElementy(ile);
tablica.zwolnijPamiec();
return 0;
}
