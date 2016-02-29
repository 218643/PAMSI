#ifndef ZAJECIA_H
#define ZAJECIA_H

class tablica
{
private:
int *pamelem; //dynamicznie lokowana pamiec
int wymiar;   //wymair tablicy

public:
int zwieksztab();
bool pelna();
bool zapisz();


};

#endif // ZAJECIA_H
