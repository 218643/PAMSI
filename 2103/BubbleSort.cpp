#include <iostream>
#include <cstdlib>
using namespace std;

/* Algorytm działa w nastepujacy sposób: Tworzy tablice 20 elementowa(rozmiar mozliwy do zmiany w kodzie), nastepnie losowo wypelnia ja elementami.
Po wypełnieniu sprawdza czy kolejny element jest większy od poprzedniego. Jeśli jest to omija pętle, jeśli nie jest większy to przypisuje jego wartość do zmeinnej temp.
Nastepnie wartość elementu mniejszego nadpisuje na element który był elementem poprzdnim. Wartosc elementu wiekszego ze zmeinnej temp kieruje na kolejny w tablicy element.
Sortuje od namjniejszej do najwiekszej
*/

void sortuj(int tab[], int rozmiar)
{
    int temp;
    bool wszystko = false;
    while (wszystko == false)
    {
        wszystko = true;
        for (int i=1; i < rozmiar; i++)
        {
            if(tab[i]<tab[i-1])
                {
                    wszystko = false;
                    temp = tab[i];
                    tab[i] = tab[i-1];
                    tab[i-1] = temp;
                }
        }
    }
}







int main() {
    int rozmiar = 20;
    int tab[rozmiar];


   for (int i = 0; i<rozmiar; i++)
        tab[i]=rand(); //przypisanie kazdemu z elementow losowej wartosci.
for (int i = 0; i < rozmiar; i++)
    cout<<"Przed sortowaniem:"<<"Tab{"<<i<<"}="<<tab[i]<<endl;
    cout<<endl;
    cout<<"Sortuje od najmniejszej do najwiekszej"<<endl<<endl;
sortuj(tab,rozmiar);

for (int i = 0; i < rozmiar; i++)
    cout<<"Po sortowaniu:"<<"Tab{"<<i<<"}="<<tab[i]<<endl;



}

