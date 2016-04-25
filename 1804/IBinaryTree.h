#pragma once
///dodawanie elementu (put albo insert)
///przeszukanie

 class IBinarryTree
 {
    public:
    virtual void insertElement(int x) = 0;
    virtual void searchElement(int x) = 0;

 };
