#include "Lista.h"

int Lista::Size()
{
return rozmiar;
}

bool Lista::IsEmpty(){
    return (rozmiar == 0);
}

void Lista::Add(std::string item , int index)
{
if (rozmiar < index)
cout<<"Lista jest za mala"<<endl;
    else if (index == 0){
    Node* nodetmp = new Node();
    nodetmp->wartosc = item;
    nodetmp->wskaznik = wskaznikPOCZ; ///dostawiam element na poczatku i wskazuje na wczesniejszy element
    wskaznikPOCZ = nodetmp; ///aktualizowanie poczatkowoego wskaznika na nowo dodany element
    wskaznikKON = nodetmp; ///aktualizowanie koncowego+ wskaznika na nowo dodany element
    rozmiar ++;}

    else if (index == rozmiar){
    Node* nodetmp = new Node();
    nodetmp->wartosc = item;
    wskaznikKON->wskaznik = nodetmp;///wskaznik koncowy wskazuje na podpiete nowe pole w liscie
    wskaznikKON = nodetmp;
    rozmiar ++;}

    else {
    Node* nodetmp = new Node();
    nodetmp->wartosc = item;
    Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
    for(int i=0; i < index-1 ; i++)
    temp = temp->wskaznik; /// przestawiamy sie na kolejny element
    Node* nastepny = temp->wskaznik; ///pomocniczy wskaznik
    temp->wskaznik = nodetmp; ///wskazuje na nowo stworzony element
    nodetmp->wskaznik = nastepny; ///w nowo dodanym elemencie ustawiamy wskaznik na wczesniejszy(ktory jest nastepnym) elementem.
    rozmiar ++;
    }
}
void Lista::Remove (int index){
if(index == 0)
{
Node* temp=wskaznikPOCZ->wskaznik; ///zapamietaj drugi element listy
delete wskaznikPOCZ; ///usun pierwszy element
wskaznikPOCZ = temp; ///przestaw drugi na pierwszy
rozmiar --;
}
else if (index == rozmiar){
Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
for(int i=0; i < index-2 ; i++)
    temp = temp->wskaznik; /// przestawiamy sie na kolejny element
temp->wskaznik = nullptr;
delete wskaznikKON;
wskaznikKON = temp;
rozmiar --;
}
else{
Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
for(int i=0; i < index-2 ; i++)
    temp = temp->wskaznik;
Node* nastepnik = temp->wskaznik->wskaznik;
delete temp->wskaznik;
temp->wskaznik = nastepnik;
rozmiar --;
}
}
std::string Lista::Get(int index){
Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
for(int i=0; i < index-1 ; i++)
    temp = temp->wskaznik;
return temp->wartosc;
}



