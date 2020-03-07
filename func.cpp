#ifndef FUNC.CPP
#define FUNC.CPP
#include "head.h"
void generavimas(int studSk, std::vector<mokinys>& A)
{
    A.resize(studSk);
        for(int i=0; i<A.size(); i++)
            {
            double vid=0;
            A[i].vardas = "Vardas" + std::to_string(rand()%100);
            A[i].pavarde = "Pavarde" + std::to_string(rand()%100);
            int ndSk = 15;
            for(int j=0; j<ndSk; j++)
            {

                A[i].pazymiai[j] = rand()%10;
                vid+=A[i].pazymiai[j];
            }
        double vidurkis = vid/15*1.0, egz;
        egz = rand()%10;
        double med;
        if(ndSk%2==0)med = (A[i].pazymiai[(ndSk/2)-1] + A[i].pazymiai[ndSk/2]) / 2;
        else if(ndSk%2==1)med = A[i].pazymiai[ndSk/2];
        A[i].Galutinis = vidurkis*0.4 + egz*0.6;
        A[i].mediana = med*0.4 + egz*0.6;
        }
}
void irasymas(int studSk, std::vector<mokinys>& A){
    std::ofstream ofs("Sarasas.txt");
    for(int i=0; i < studSk; i++)
    {
        ofs << A[i].vardas;
        for(int j=0; j<10-A[i].vardas.size(); j++)
        {
            ofs << " ";
        }
        ofs << A[i].pavarde;
        for(int j=0; j<15-A[i].pavarde.size(); j++)
        {
            ofs << " ";
        }
        ofs << std::fixed << std::setprecision(2)<< A[i].Galutinis << "  ";
        ofs << std::fixed << std::setprecision(2)<< A[i].mediana<<std::endl;
    }
    ofs.close();
}
void rusiavimas(int studSk, std::vector<mokinys>& A)
{
    std::ofstream maz("Vargsiukai.txt");
    std::ofstream daug("Kietiakai.txt");
    for(int i=0; i < studSk; i++){
    if(A[i].Galutinis<=5.0)
    {
        maz << A[i].vardas;
        for(int j=0; j<10-A[i].vardas.size(); j++)
        {
            maz << " ";
        }
        maz << A[i].pavarde;
        for(int j=0; j<15-A[i].pavarde.size(); j++)
        {
            maz << " ";
        }
        maz << std::fixed << std::setprecision(2)<< A[i].Galutinis << "  ";
        maz << std::fixed << std::setprecision(2)<< A[i].mediana<<std::endl;
    }
    else
    {
        daug << A[i].vardas;
        for(int j=0; j<10-A[i].vardas.size(); j++)
        {
            daug << " ";
        }
        daug << A[i].pavarde;
        for(int j=0; j<15-A[i].pavarde.size(); j++)
        {
            daug << " ";
        }
        daug << std::fixed << std::setprecision(2)<< A[i].Galutinis << "  ";
        daug << std::fixed << std::setprecision(2)<< A[i].mediana<<std::endl;
    }
    }
}
void nuskaitymas(int studSk, std::vector<mokinys>& B){
    std::ifstream ifs("Sarasas.txt");
    char a[256];
    char info[studSk];
    for(int i=0; i < studSk; i++)
    {
        ifs.getline(a, 256);
    }
    ifs.close();
}
#endif

