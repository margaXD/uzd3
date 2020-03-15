#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <list>
#include <deque>
struct mokinys{
    std::string vardas;
    std::string pavarde;
    int pazymiai[15];
    double Galutinis;
    double mediana;
};
void nuskaitymas(int studSk, std::deque<mokinys>& B,std::vector<mokinys> A);
void rusiavimas(int studSk, std::deque<mokinys>& A);
//void irasymas(int studSk, std::vector<mokinys>& A);
//void generavimas(int studSk, std::vector<mokinys>& A);
#endif
