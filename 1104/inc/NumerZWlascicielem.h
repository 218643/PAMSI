#pragma once

#include <string>

struct NumerZWlascicielem
{
 NumerZWlascicielem(std::string wlasc,int numer) :wlasciciel(wlasc), numer_tel(numer) {}
  NumerZWlascicielem() = default;
  std::string wlasciciel;
  int numer_tel;
};
