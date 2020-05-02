#ifndef head_h
#define head_h
#include "header.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <random>
#include <string>
#include <istream>
#include <vector>
#include <fstream>
#include <chrono>
#include <list>
#include <deque>
#include <iterator>
#include <ctime>
#include <cmath>

using namespace std;
int pradzia();
bool compare(const Stud& a, const Stud& b);
bool XD(const Stud& a, const Stud& b);
void rusiavimasL(list<Stud>& Sstud, list<Stud>& error);
void rusiavimasL2(list<Stud>& Sstud, list<Stud>& error, list<Stud>& Nero);
template <typename T1>
void nuskaitymas(T1& Sstud, int& vardas, int& pavarde)
{
    Stud Studentai;
    string gal;
    int x;
    int sum;
    int y = 0;
    std::ifstream fd("Sarasas.txt");
    if (fd)
    {
        string Vvardas, Ppavarde;
        vector<int> nd;
        double galvid;
        int egzas;
        string pirmaEil;
        string D;
        fd.getline(pirmaEil, 256);
        while (!fd.eof())
        {
            std::istringstream fdd(D);
            fdd >> Studentai;
            sum = 0;
            for (int i = 0; i < 5; i++)
            {
                fd >> x;
                Studentai.nd.push_back(x);
                sum = sum + x;
            }
            Stud X(Studentai);
            nd.clear();
            Sstud.push_back(X);
        }
        fd.close();
    }
    else
    {
        cout << "good" << endl;
        cout << "Failas nerastas" << endl;
        nuskaitymas(Sstud, vardas, pavarde);
        return;
    }
};
template<typename T1, typename T2>
void rusiavimas(T1& Sstud, T2& error)
{
    std::sort(Sstud.begin(), Sstud.end(), compare);
    std::sort(Sstud.begin(), Sstud.end(), XD);
    int dyd = Sstud.size();
    for (int i = 0; i < dyd; i++)
    {
        if (Sstud.at(i).Galutinis() < 5)
        {
            error.push_back(Sstud.at(i));
            Sstud.erase(Sstud.begin() + i);
            i--;
            dyd--;
        }
    }
};
template<typename T1, typename T2, typename T3>
void rusiavimas2(T1& Sstud, T2& error, T3& Nero)
{
    std::sort(Sstud.begin(), Sstud.end(), compare);
    std::sort(Sstud.begin(), Sstud.end(), XD);
    int x = Sstud.size();
    for (int i = 0; i < x; i++)
    {
        if (Sstud.at(i).Galutinis() < 5) error.push_back(Sstud.at(i));
        else Nero.push_back(Sstud.at(i));
    }
};

template<typename T>
void spausdinimas(T Sstud, int Vvardas, int Ppavarde, string X)
{
    auto it = Sstud.begin();
    std::ofstream fr(X);
    int x = Sstud.size();
    for (int i = 0; i < x; i++)
    {
        fr << std::left << std::setw(Vvardas) << it->Vardas() << std::setw(Ppavarde) << it->Pavarde() << std::setprecision(3) << it->Galutinis() << endl;
        it++;
    }
    fr.close();
};
#endif
