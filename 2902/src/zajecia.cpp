#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Tablica {
private:
    int *tablica;

public:
    int dodajElementy(int n){
        tablica= new int [n];{
        for (int i=0;i<n,i++);
        tablica[n]=rand();
    }
 }
    void zwolnijPamiec(){
        delete [] tablica;
        }

};

clock_t start, stop;
double czas;

int main()
{
/*
n[5]={10^1,10^3,10^5,10^6,10^9};
*/
start=clock();
for (int i=0;i<5;i++);
Tablica tablica;
int ile=5;
tablica.dodajElementy(ile);
tablica.zwolnijPamiec();

stop=clock();
czas= (double)(stop-start);
cout<<"Czas zapisu(przy zwiekszaniu o jeden):"<<czas<<endl;
return 0;

}



