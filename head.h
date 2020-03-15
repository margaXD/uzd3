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
struct mokinys{
    std::string vardas;
    std::string pavarde;
    int pazymiai[15];
    double Galutinis;
    double mediana;
};
void nuskaitymas(int studSk, std::vector<mokinys>& B);
void rusiavimas(int studSk, std::vector<mokinys>& A);
void irasymas(int studSk, std::vector<mokinys>& A);
void generavimas(int studSk, std::vector<mokinys>& A);
#endif