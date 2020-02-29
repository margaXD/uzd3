#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include "head.h"

using namespace std;
int main()
{
    vector<string> vardas;
    vector<string> pavarde;
    vector<double> vidurkisvec;
    vector<double> medianavec;
    vector<int> pazymiai;
    ifstream excp;
    excp.exceptions(ifstream::badbit);
    try{
    excp.open("kursiokai.txt");
    char ch;
    while(excp.get(ch)) xDbandymas(ch);
    }
    catch(const ifstream::failure& e){
    cout<<"Exception'as rastas atidarant/skaitant faila";
    }
    excp.close();
      ifstream duom("kursiokai.txt");
    cout<<"2 - skaitymas is failo, 1 - generavimas, 0 - rankinis ivedimas"<<endl;
    int gen;
    cin>>gen;
    long int studSk;
    string laikV, laikP;
    int laikN;
    if(gen==0){
    cout<<"Iveskite studentu skaiciu (nuo 1 iki 100)"<<endl;
    int studSk;
    cin>>studSk;
    if(studSk>0&&studSk<100){
    for(int j=0; j<studSk; j++)
        {
        cout << "Vardas?" <<endl;
          cin >> laikV;
          vardas.push_back(laikV);
        cout << "Pavarde?" <<endl;
          cin >> laikP;
          pavarde.push_back(laikP);
        double vid=0;
        cout<<" Iveskite nd pazymius: (jeigu baiget, parasykit 11) (0 nera pazymys)"<<endl;
        int i = 0;
        int pazymys;
        while(true)
        {
            cin >> pazymys;
            if(pazymys==0){cout<<"ivedete bloga pazymi"<<endl;
            cout<<"Programos pabaiga"<<endl;
            return 0;
            }
            else if (pazymys==11)break;
            else{
            pazymiai.push_back(pazymys);
            vid+=pazymys;
            i++;}
        }
        double vidurkis = vid/i*1.0, egz;
        cout << "Egzamino rezultatas?" <<endl;
        cin >> egz;
        vidurkisvec.push_back(vidurkis*0.4 + egz*0.6);
        medianavec.push_back((vidurkis+egz)/2);
        pazymiai.erase(pazymiai.begin(),pazymiai.begin()+i);
        }
    }
    else {
            cout<<"Blogas mokiniu skaicius";
            return 0;
            }
    }
        else if(gen==2){
        int vid;
        string laikV, laikP;
        int laikN;
        studSk = 1000;
        for(int i=0; i < studSk; i++)
        {
          vid=0;
          duom >> laikV;
          vardas.push_back(laikV);
          duom >> laikP;
          pavarde.push_back(laikP);
          for(int j=0; j<15; j++)
          {
            duom >> laikN;
            vid+=laikN;
          }
        double vidurkis = vid/15*1.0, egz;
          duom >> egz;
        vidurkisvec.push_back(vidurkis*0.4 + egz*0.6);
        medianavec.push_back((vidurkis+egz)/2);
        }
        }
        else if(gen==1){
        cout<<"Iveskite studentu skaiciu (nuo 1 iki 100)"<<endl;
        int studSk;
        cin>>studSk;
        if(studSk>0&&studSk<100){
        for(int i=0; i<studSk; i++)
        {
            double vid=0;
            vardas.push_back("Vardas" + to_string(rand()%100));
            pavarde.push_back("Pavarde" + to_string(rand()%100));
            for(int j=0; j<15; j++)
            {
                pazymiai.push_back(rand()%10);
                vid+=pazymiai.at(j);
            }
        double vidurkis = vid/15*1.0, egz;
        egz = rand()%10;
        vidurkisvec.push_back(vidurkis*0.4 + egz*0.6);
        medianavec.push_back((vidurkis+egz)/2);
        pazymiai.erase(pazymiai.begin(),pazymiai.begin()+15);
        }
    }
    else {cout<<"Blogas mokiniu skaicius"; return 0;}
        }
    else {cout << "Klaida su studentu skaiciumi - skaicius per didelis, per mazas arba net ne skaicius"<<endl;
    return 0;}
    bool vidmed;
    rusiavimas(vardas,pavarde,vidurkisvec,medianavec);
    cout<<"Vardas         "<<"Pavarde       "<<"Galutinis(Vid.) "<<"Galutinis(Med.)"<<endl;
    cout <<"------------------------------------------------"<<endl;
    int s;
    for(int i=0; i<pavarde.size(); i++)
    {
        cout<<pavarde.at(i);
        s = 15 - pavarde[i].size();
        for(int j=0; j<s; j++)
        {
            cout<<" ";
        }
        cout<<vardas.at(i);
        s = 15 - vardas[i].size();
        for(int j=0; j<s; j++)
        {
            cout<<" ";
        }
        cout<<fixed<<setprecision(2)<<vidurkisvec.at(i);
        s = 15 - 3;
        for(int j=0; j<s; j++)
        {
            cout<<" ";
        }
        cout<<fixed<<setprecision(2)<<medianavec.at(i)<<endl;
    }
    duom.close();
    cout<<"Programos pabaiga"<<endl;
    return 0;
}
