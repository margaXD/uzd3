#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
struct mokinys{
    string vardas;
    string pavarde;
    double Galutinis;
    double mediana;
};

int main()
{
    cout<<"2 - skaitymas is failo, 1 - generavimas, 0 - rankinis ivedimas"<<endl;
    int gen;
    cin>>gen;
    int studSk;
    vector<string> vardas = {};
    vector<string> pavarde = {};
    vector<double> vidurkisvec = {};
    vector<double> medianavec = {};
    vector<int> pazymiai = {};
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
        ifstream duom("kursiokai.txt");
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
    for(int i=0; i<pavarde.size(); i++)
    {
        string tempV;
        string tempP;
        double tempVid;
        double tempMed;
        for(int j=i+1; j<pavarde.size(); j++) // RIKIAVIMAS PAGAL PAVARDE
        {
            if(pavarde.at(i)<pavarde.at(j))
            {
                tempP = pavarde.at(i);
                pavarde.at(i) = pavarde.at(j);
                pavarde.at(j) = tempP;
                tempV = vardas.at(i);
                vardas.at(i) = vardas.at(j);
                vardas.at(j) = tempV;
                tempVid = vidurkisvec.at(i);
                vidurkisvec.at(i) = vidurkisvec.at(j);
                vidurkisvec.at(j) = tempVid;
                tempMed = medianavec.at(i);
                medianavec.at(i) = medianavec.at(j);
                medianavec.at(j) = tempMed;
            }
        }
    }
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
    cout<<"Programos pabaiga"<<endl;
    return 0;
}
