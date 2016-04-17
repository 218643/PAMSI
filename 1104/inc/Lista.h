#pragma once
#include <string>
#include <iostream>

template<typename T>
struct Node ///pojedynczy element
{
  Node* wskaznik;
  T wartosc;
};

/*!
 *\brief Deklaruje funkcje listy.
 */
template<typename T>
class Lista
{
 public:
  /*!
   *Funkcja Add dodaje kolejny element listy.
   *Jesli rozmiar listy jest za maly w stosunku do podawanego indexu to wyswietla komunikat.
   *Funkcja dziala w taki sposob, ze tworzy nowy "Node" do tablicy, wskaznik z wczesniejszego elementu wskazuje na nowy Node
   *nastepnie z Node wskazujemy na kolejny element tablicy, aby byla ciaglosc w liscie.
   *W tej funkcji rozpatrujemy 3 przypadki zwieksznaia listy, dostawianie elementu na pocz,koniec lub gdzies pomiedzy w liscie.
   *Jesli dostawiamy na poczatek tworzymy nowy element i wskazujemy na niego wskaznikiem poczatkowym i koncowym.
   *Jesli tworzymy ostatni element, to dodajemy nowego Noda, i wskazujemy na niego wskaznikiemKONcowym.
   *Osttanim przypadkiem jest elementu gdzies pomiedzy POCZ i KON listy.
   *Tutaj musimy pamietac ze lista liczy swojem miejsca od 0, wiec w petli for mamy index-1.
   *Tworzymy tymczasowy wskaznik i ustawiamy go na pierwszy element.
   *nastepnie w petli przesówamy o tyle elementów ile zadamy-1. Przesuwamy ten wskaznik na kolejny element, tworzymy pomocniczy wskaznik
   *ktory ma wskazywac na nowo utworzony element. W nowo utworzonym elemencie dodajemy wskaznik ktory wskazuje na nastepny element
   *ktory byl stworzony przed naszym nowym Nodem.Wszystko po to by zachowac ciaglosc listy i wskazywanie na kolejne elementy.
   */
  void Add(T item, int index) //dodawanie elemntow
  {
    if (rozmiar < index)
      std::cout<<"Lista jest za mala"<<std::endl;
    else if (index == 0){
      Node<T>* nodetmp = new Node<T>();
      nodetmp->wartosc = item;
      nodetmp->wskaznik = wskaznikPOCZ; ///dostawiam element na poczatku i wskazuje na wczesniejszy element
      wskaznikPOCZ = nodetmp; ///aktualizowanie poczatkowoego wskaznika na nowo dodany element
      wskaznikKON = nodetmp; ///aktualizowanie koncowego+ wskaznika na nowo dodany element
      rozmiar ++;}

    else if (index == rozmiar){
      Node<T>* nodetmp = new Node<T>();
      nodetmp->wartosc = item;
      wskaznikKON->wskaznik = nodetmp;///wskaznik koncowy wskazuje na podpiete nowe pole w liscie
      wskaznikKON = nodetmp;
      rozmiar ++;}

    else {
      Node<T>* nodetmp = new Node<T>();
      nodetmp->wartosc = item;
      Node<T>* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
      for(int i=0; i < index-1 ; i++)
        temp = temp->wskaznik; /// przestawiamy sie na kolejny element
      Node<T>* nastepny = temp->wskaznik; ///pomocniczy wskaznik
      temp->wskaznik = nodetmp; ///wskazuje na nowo stworzony element
      nodetmp->wskaznik = nastepny; ///w nowo dodanym elemencie ustawiamy wskaznik na wczesniejszy(ktory jest nastepnym) elementem.
      rozmiar ++;
    }
  }

  /*!
   *Remove dziala w podobny sposob. Jesli zadamy usuniecie 1 elementu, to zapamietujemy cos na co wskazuje 1 element. Usuwamy to,
   *by nastepnie ustawic wskaznik poczatkowy na cos, na co wskazywal pierwszy element.
   *Jesli usuwamy ostatni element to tworzymy wskaznik tymczasowy na pierwszy element, przesuwamy do ostatniego, gdzie index zmniejszamy -2,
   *poniewaz indexujemy liste od zera, oraz interesuje nas wczesniejszy element ktory wskazuje na ostatni. Gdy osiegniey przedostatni element wskazujemy
   *jego wskaznikiem na null pointer oraz usuwamy wczesniejszy osttni element z listy na ktorego nic nie wskazuje.
   *W ostatnim przypadku tworzymy tymczasowy nastepnik , ktory jest wskaznikiem na wskaznik. Przesukujemy liste od poczatku, usuwamy element
   *i nasz wskaznik dalej wskazuje na kolejny element dzieki nastepnikowi. Zachowana jest ciaglosc wskazywania na siebie elementow z listy.
   */
  void Remove(int index)  //usuwanie elementow
  {
    if(index == 0)
    {
      Node<T>* temp=wskaznikPOCZ->wskaznik; ///zapamietaj drugi element listy
      delete wskaznikPOCZ; ///usun pierwszy element
      wskaznikPOCZ = temp; ///przestaw drugi na pierwszy
      rozmiar --;
    }
    else if (index == rozmiar){
      Node<T>* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
      for(int i=0; i < index-2 ; i++)
        temp = temp->wskaznik; /// przestawiamy sie na kolejny element
      temp->wskaznik = nullptr;
      delete wskaznikKON;
      wskaznikKON = temp;
      rozmiar --;
    }
    else{
      Node<T>* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
      for(int i=0; i < index-2 ; i++)
        temp = temp->wskaznik;
      Node<T>* nastepnik = temp->wskaznik->wskaznik;
      delete temp->wskaznik;
      temp->wskaznik = nastepnik;
      rozmiar --;
    }
  }

  /*!
   *Zwraca true jesli lista jest pusta lub false jesli nie jest.
   */
  bool IsEmpty() //sprawdzanie czy pusta
  {
    return (rozmiar == 0);
  }

  /*!
   *W tej funkcji tworzymy wskaznik tymczasowy na 1 element listy, przesuwamy o index-1 , po znalezieniu interesujacego nas elementu zwracamy jego wartosc.
   */
  T Get(int index) //pobiera elemento z listy
  {
    Node<T>* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
    for(int i=0; i < index-1 ; i++)
      temp = temp->wskaznik;
    return temp->wartosc;
  }
  /*!
   *Size zwraca nam zmienna rozmiar.
   */
  int Size() //wyswietla rozmiar listy
  {
    return rozmiar;
  }
  Lista() : wskaznikPOCZ(nullptr) , wskaznikKON(nullptr) , rozmiar(0){}
 private:
  int rozmiar;
  Node<T>* wskaznikPOCZ;//wsk.na pierwzy element listy
  Node<T>* wskaznikKON; //wskaznik na ostati el listy
};
