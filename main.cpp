#include "head.h"
using namespace std;
int main()
{
    int studSk;
    std::clock_t start, visas;
    cout<<"Generuoti kiek?(1000,10000,100000,1000000)"<<endl;
    cin>>studSk;
    list<mokinys> B;
    vector<mokinys> A;
    //generavimas(studSk, A);
    /*start = std::clock();
    irasymas(studSk, A);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"irasymas uztruko "<<duration<<" s"<<endl;*/
    visas = std::clock();
    start = std::clock();
    nuskaitymas(studSk, B, A);
    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"Nuskaitymas uztruko "<<duration<<" s"<<endl;
    start = std::clock();
    rusiavimas(studSk, B);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"rusiavimas uztruko "<<duration<<" s"<<endl;
    duration = ( std::clock() - visas ) / (double) CLOCKS_PER_SEC;
    cout<<"Visas kodas uztruko "<<duration<<" s"<<endl;
}
