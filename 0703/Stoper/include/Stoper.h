#pragma once ///zastepuje kilkukrotne wklejanie pliku naglowkowego

#include <iostream>
#include <chrono>
#include <string>
#include <fstream>

#include "IStoper.h"

class Stoper :public IStoper {
public:

void Start();
void Stop();
double getElapsedTime();
void dumpToFile(std::string const&); ///const& =unikamy kopi

using clock = std::chrono::high_resolution_clock;///czas systemowy
using time_point = clock::time_point;
using time_type = std::chrono::milliseconds;

private:
time_point punkt_startowy;
time_point punkt_koncowy;
};
