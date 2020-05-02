#include "head.h"

int pradzia() {
    cout << endl << " Pasirinkite tiksla " << endl;
    cout << "Programos greicio matavimas priklausomai nuo nuskaitymo ir generavimo - 1" << endl;
    cout << " Vektroiaus greitis - 2" << endl;
    cout << " Konteineriu sparta - 0" << endl;
    cout << "Konteineriu sparta rusiuojant - 3" << endl;
    int x;
    for (int i = 0; i < 1; i++)
    {
        cin >> x;
        if (cin.fail() || ((x != 1) && (x != 2) && (x != 3)))
        {
            cin.clear();
            cin.ignore();
            cout << "Blogai, try again.." << endl;
            i--;
        }
    }
    cout << endl;
    return x;
}

void IvedGen(vector<Stud>& Sstud, int& Vvardas, int& Ppavarde)
{
    cout << "Nuskaitymas - 1, Ivedimas - 2" << endl;
    int x;
    for (int i = 0; i < 1; i++)
    {
        cin >> x;
        if (cin.fail() || ((x != 1) && (x != 2)))
        {
            cin.clear();
            cin.ignore();
            cout << "Blogai, try again.." << endl;
            i--;
        }
    }
    if (x == 1)nuskaitymas(Sstud, Vvardas, Ppavarde);
    /* else
     {
         cout << "studentu skaicius: ";
         int q;
         for(int i = 0; i < 1; i++)
         {
             cin >> q;
             if(cin.fail()||q<1)
             {
                 cin.clear();
                 cin.ignore();
                 cout << "Blogai, try again.." << endl;
                 i--;
             }
         }
     }
     string vard, pavard;
     vector<int> nd;
     int egzas;
     double galvid;
     for(int i=0; i<q; i++)
     {
     }*/
}
bool XD(const Stud& a, const Stud& b)
{
    return a.Galutinis() < b.Galutinis();
}
bool compare(const Stud& a, const Stud& b)
{
    return a.Vardas() < b.Vardas();
}
void rusiavimasL(list<Stud>& Sstud, list<Stud>& error)
{
    Sstud.sort(compare);
    Sstud.sort(XD);
    auto it = Sstud.begin();
    int x = Sstud.size();
    for (int i = 0; i < x; i++)
    {
        if (it->Galutinis() < 5)
        {
            Stud a(it->Vardas(), it->Pavarde(), it->Galutinis());
            error.push_back(a);
            Sstud.erase(it);
            it = Sstud.begin();
            advance(it, i);
            i--;
            x--;
        }
        else it++;
    }
}
void rusiavimasL2(list<Stud>& Sstud, list<Stud>& error, list<Stud>& Nero)
{
    Sstud.sort(compare);
    Sstud.sort(XD);
    auto it = Sstud.begin();
    int x = Sstud.size();
    for (int i = 0; i < x; i++)
    {
        if (it->Galutinis() < 5)
        {
            Stud a(it->Vardas(), it->Pavarde(), it->Galutinis());
            error.push_back(a);
        }
        else
        {
            Stud a(it->Vardas(), it->Pavarde(), it->Galutinis());
            Nero.push_back(a);
        }
        it++;
    }
}
