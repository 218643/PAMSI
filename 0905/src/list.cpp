#include "list.hh"
#include <iostream>

List::List() {
front = NULL;
end = NULL;
}

List::~List() {}

void List::add(const int& elem, int i) {
/* Jesli zostanie podany zly indeks to wypluje wyjatek */
    Node* v = new Node;
    Node* tmp = new Node;
    v->elem=elem;

    if(i>1 && i<size()+1 && size()!=0) {
    Node* f = front;
    for(int j=1; j<(i-1); j++)
    f=f->next; // szukamy wezla poprzedzajacego
    tmp=f->next;
    f->next=v; // wklejamy element pomiedzy dwa wezly
    v->next=tmp;
    list_size++;
    }
    else if(i==1 && (size()==0)) { // jesli na pierwsze miejsce i lista jest pusta
    front=v;
    end=v;
    list_size++;
    }
    else if(i==1 && (size()>0)) {
        v->next=front;
        front=v;
        list_size++;
    }
    else if(i==size()+1 && size()>0) {
    Node* e = end;
    if(size()!=0) {
    e->next=v;
    v->next=NULL;
    end=v;
    list_size++;
    }
    }
    else {
    std::string WrongListIndexException = "Lista nie ma takiego pola, sprawdz najpierw rozmiar!";
    throw WrongListIndexException; // wyrzuca wyjatek jesli blednie wpisano pole
    }
}

int List::remove(int i) {
    if(i==1) {
    if(size()!=0) {
        Node* old=front;
        front=old->next;
        list_size--;
        int temp=old->elem;
        delete old; // usuwamy pierwszy element
        return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli pusta
    }
    }
    else if(i==size() && i>1) {
    Node* v = front;
    Node* e = end;
    if(size()!=0) { // tylko jesli nie jest pusta
            while(v->next->next)
            v=v->next;
            v->next=NULL;
            end=v;
            list_size--;
            int temp= e->elem;
            delete e;
            return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli lista jest pusta
    }
    }
    else if(i>1 && i<size()) {
    Node* f = front;
    if(size()!=0) {
            for(int j=1; j<(i-1); j++)
            f=f->next;
            Node* tmp = f->next;
            f->next=f->next->next; // przepinamy wskaźnik
            int temp = tmp->elem;
            list_size--;
            delete tmp; // usuwamy element i zwracamy
            return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli jest pusta
    }
    }
    else {
    std::string WrongListIndexException = "Lista nie ma takiego pola, pamietaj o numeracji!";
    throw WrongListIndexException; // wyrzuca wyjatek jesli zly indeks
    }
}

int List::size() {
    return list_size;
}

int List::at(int i) {

    Node* f = front;

    for(int j=1; j<i; j++)
    f=f->next;

    return f->elem;
}

void List::show_list() {
    Node* tmp = front;
    if(size()!=0) { // jesli nie jest pusta
    std::cout<<"Elementy listy:"<<std::endl;
    std::cout<<tmp->elem<<std::endl; // wypisujemy pierwszy
        while(tmp->next) { // jesli cos procz pierwszego to tez wypisujemy
        tmp=tmp->next;
        std::cout<<tmp->elem<<std::endl;
        }
    }
    else
        std::cout<<"Lista jest pusta!"<<std::endl;
}
