#pragma once


class Lista
{
    public:
        void Add();
        void Remove();
        double IsEmpty();
        void Get();


    void LPushFront(int v)
{
  skladnik * p = new skladnik;
  p->val = v;
  p->next = start;
  start = p;  // nowy początek listy
}
};

