#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <fstream>
struct mokinys{
    std::string vardas;
    std::string pavarde;
    double vidurkisvec;
    double medianavec;
    int pazymiai;
};
void rusiavimas(std::vector<std::string> &vardas, std::vector<std::string> &pavarde, std::vector<double> &vidurkisvec, std::vector<double> &medianavec);
void xDbandymas(char xD);
#endif
