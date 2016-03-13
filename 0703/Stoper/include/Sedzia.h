#pragma once

#include "IRunnable.h"
#include "IStoper.h"

#include <fstream>
#include <string>
#include <iostream>

const std::string NAZWA_PLIKU_Z_ILOSCIA_ELEMENTOW = "dystans.txt";

class Sedzia
{
  IRunnable & _biegacz;
  IStoper & _stoper;
public:
Sedzia(IRunnable & biegacz, IStoper & stoper) :_biegacz(biegacz), _stoper(stoper) {}
  void release();
};
