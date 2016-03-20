#pragma once
#include <string>
#include <iostream>
#include "Lista.h"

using namespace std;

class Stos : private Lista
{
private:
void empty ();
std::string top();
void push ();
void pop();
void size ();


}
