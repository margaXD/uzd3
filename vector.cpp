#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
using namespace std;
struct mokinys{
    string vardas;
    string pavarde;
    double Galutinis;
    double mediana;
};

int main()
{
    cout<<"Iveskite studentu skaiciu (nuo 1 iki 100)"<<endl;
    int studSk;
    vector<int> pazymiai = {};
    cin>>studSk;
    if(studSk>0&&studSk<100){
    cout<<"1 - generavimas, 0 - rankinis ivedimas"<<endl;
    bool gen;
    cin>>gen;
    mokinys A[studSk];
    if(gen==false){
    for(int j=0; j<studSk; j++)
        {
        cout << "Vardas?" <<endl;
        cin >> A[j].vardas;
        cout << "Pavarde?" <<endl;
        cin >> A[j].pavarde;
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
        A[j].Galutinis = vidurkis*0.4 + egz*0.6;
        A[j].mediana = (vidurkis+egz)/2;
        pazymiai.erase(pazymiai.begin(),pazymiai.begin()+i);
    }
    }
    else {
        for(int i=0; i<studSk; i++)
        {
            double vid=0;
            A[i].vardas = "Vardas" + to_string(rand()%100);
            A[i].pavarde = "Pavarde" + to_string(rand()%100);
            for(int j=0; j<5; j++)
            {
                pazymiai.push_back(rand()%10);
                vid+=pazymiai.at(j);
            }
        double vidurkis = vid/5*1.0, egz;
        egz = rand()%10;
        A[i].Galutinis = vidurkis*0.4 + egz*0.6;
        A[i].mediana = (vidurkis+egz)/2;
        pazymiai.erase(pazymiai.begin(),pazymiai.begin()+5);
        }
    }
    bool vidmed;
    cout << "1 - vidurkis, 0 - mediana"<<endl;
    cin >>vidmed;
    cout <<"Pavarde        "<<"Vardas         ";
    if(vidmed==true)cout<<"Galutinis(Vid.)"<<endl;
        else cout<<"Galutinis(Med.)"<<endl;
    cout <<"----------------------------------------------"<<endl;
    int s;
    for(int i=0; i<studSk; i++)
    {
        cout<<A[i].pavarde;
        s = 15 - A[i].pavarde.length();
        for(int j=0; j<s; j++)
        {
            cout<<" ";
        }
        cout<<A[i].vardas;
        s = 15 - A[i].vardas.length();
        for(int j=0; j<s; j++)
        {
            cout<<" ";
        }
        if(vidmed==true)cout<<fixed<<setprecision(2)<<A[i].Galutinis<<endl;
            else cout<<fixed<<setprecision(2)<<A[i].mediana<<endl;
    }
    }
    else cout << "Klaida su studentu skaiciumi - skaicius per didelis, per mazas arba net ne skaicius"<<endl;
    cout<<"Programos pabaiga"<<endl;
    return 0;
}
