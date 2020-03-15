#include "head.h"
using namespace std;
int main()
{
    int studSk;
    std::clock_t start, visas;
    cout<<"Generuoti kiek?(1000,10000,100000,1000000)"<<endl;
    cin>>studSk;
    visas = std::clock();
    vector<mokinys> A;
    vector<mokinys> B;
    start = std::clock();
    generavimas(studSk, A);
    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"generavimas uztruko "<<duration<<" s"<<endl;
    start = std::clock();
    irasymas(studSk, A);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"irasymas uztruko "<<duration<<" s"<<endl;
    start = std::clock();
    nuskaitymas(studSk, B);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"Nuskaitymas uztruko "<<duration<<" s"<<endl;
    start = std::clock();
    rusiavimas(studSk, A);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"rusiavimas uztruko "<<duration<<" s"<<endl;
    duration = ( std::clock() - visas ) / (double) CLOCKS_PER_SEC;
    cout<<"Visas kodas uztruko "<<duration<<" s"<<endl;
}
