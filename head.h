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
bool compare(const Stud& a,const Stud& b);
bool XD(const Stud& a,const Stud& b);
void rusiavimasL(list<Stud>& Sstud, list<Stud>& error);
void rusiavimasL2(list<Stud> & Sstud, list<Stud> & error, list<Stud> & Nero);
template <typename T1>
void nuskaitymas(T1& Sstud, int& vardas, int& pavarde)
{
    string gal;
    int d = 1;
    int x = 0;
    int sum;
    int y = 0;
    std::ifstream fd("Sarasas.txt");
    if(fd)
    {
        string Vvardas, Ppavarde;
        vector<int> nd;
        double galvid;
        int egzas;
        for(int i=0; i<3; i++){
        fd >> gal >> gal >> gal;
        }
        while (gal[0] == 'N')
        {
            y++;
            fd >> gal;
        }
        for(int j=0; j<100000; j++)
        {
            fd >> Vvardas;
            if(Vvardas.length() > vardas - 2){
            vardas = Vvardas.length() +2;}
            fd >> Ppavarde;
            if(Ppavarde.length() > pavarde - 2){
            pavarde = Ppavarde.length() + 2;
            }
            sum = 0;
            for(int i = 0; i < y; i++)
            {
                fd >> x;
                nd.push_back(x);
                sum = sum + x;
            }
            fd >> egzas;
            if(y!=0) galvid = 0.4 * sum / y + x * 0.6;
            else galvid = x * 0.6;
            Stud X(Vvardas, Ppavarde, nd, egzas, galvid);
            nd.clear();
            Sstud.push_back(X);
            /*cout <<d<< endl;
            d++;*/
        }
        fd.close();
    }
    else
    {
        cout<<"Failas nerastas"<<endl;
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
    for(int i = 0; i < dyd; i++)
    {
        if(Sstud.at(i).Galutinis() < 5)
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
        if(Sstud.at(i).Galutinis() < 5) error.push_back(Sstud.at(i));
        else Nero.push_back(Sstud.at(i));
    }
};

template<typename T>
void spausdinimas(T Sstud, int Vvardas, int Ppavarde, string X)
{
    auto it = Sstud.begin();
    std::ofstream fr(X);
    int x = Sstud.size();
    for(int i = 0; i < x; i++)
    {
        fr << std::left << std::setw(Vvardas) << it->Vardas() << std::setw(Ppavarde) << it->Pavarde() << std::setprecision(3) << it->Galutinis() << endl;
        it++;
    }
    fr.close();
};
#endif
