
#pragma once
#include "iqueue.hh"

template <typename E>
class QNode;
template <typename E>
class Queue;

 /*!
* \brief Klasa węzła kolejki.
*
* Zawiera element węzła oraz wskaźnik na następny węzeł.
*/
template <typename E>
class QNode {

friend class Queue<E>; // przyznajemy dostep do wezla klasie Queue

private:
E elem;
QNode<E>* next;

};

 /*!
* \brief Klasa kolejki.
*
* Zawiera metody umożliwiające operacje na kolejce.
*/
template <typename E>
class Queue : public IQueue<E> {

private:
QNode<E>* front;
QNode<E>* end;
int queue_size=0;

public:
Queue() {
front = NULL; // inicjalizacja NULLami poczatku i konca
end = NULL;
};
~Queue() {};

/**
 * Funkcja dodaje element do kolejki
 *
 *
 */
void add(const E& elem);

/**
 * Funkcja usuwa element z kolejki
 * Wyrzuca wyjątek EmptyQueueException jeśli kolejka jest pusta.
 *
 *
 */
E remove();

/**
 * Funkcja zwraca rozmiar kolejki
 *
 *
 */
int size();

/**
 * Funkcja wyświetla kolejkę
 *
 *
 */
void show_queue(); // pokazuje kolejke

};

template <typename E>
void Queue<E>::add(const E& elem) {
    QNode<E>* v = new QNode<E>;
    v->elem=elem;
    v->next=NULL;
    QNode<E>* e = end;
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    e->next=v;
    end=v;
    queue_size++;
    }
    else {
    front=v;
    end=v;
    queue_size++;
    }
}

template <typename E>
E Queue<E>::remove() {
    if(size()!=0) {
        QNode<E>* old=front;
        front=old->next;
        queue_size--;
        return old->elem; // zwracamy pierwszy element
        delete old;
    }
    else {
    std::string EmptyQueueException = "Kolejka jest pusta!";
    throw EmptyQueueException; // metoda wyrzuca wyjatek jesli kolejka pusta
    }
}

template <typename E>
int Queue<E>::size() {
    return queue_size;
}

template <typename E>
void Queue<E>::show_queue() {
    QNode<E>* tmp = front;
    if(tmp!=NULL) {
        std::cout<<"Elementy kolejki:"<<std::endl;
        std::cout<<tmp->elem<<std::endl;
        while(tmp->next) { // wyswietlamy elementy
        tmp=tmp->next;
        std::cout<<tmp->elem<<std::endl;
        }
    }
    else
        std::cout<<"Kolejka jest pusta!"<<std::endl;
}
