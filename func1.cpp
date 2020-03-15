#ifndef FUNC.CPP
#define FUNC.CPP
#include "head1.h"
/*void generavimas(int studSk, std::vector<mokinys>& A)
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
}*/
/*void irasymas(int studSk, std::vector<mokinys>& A){
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
}*/
void rusiavimas(int studSk, std::deque<mokinys>& A)
{
    std::ofstream maz("Vargsiukai.txt");
    std::ofstream daug("Kietiakai.txt");
    std::deque<mokinys>::iterator it;
    it = A.begin();
    while(it!=A.end()){
    if(it->Galutinis<5.0)
    {
        maz << it->vardas;
        for(int j=0; j<10-2; j++)
        {
            maz << " ";
        }
        maz << it->pavarde;
        for(int j=0; j<9; j++)
        {
            maz << " ";
        }
        maz << it->Galutinis << "  ";
        maz << it->mediana <<std::endl;
    }
    else
    {
        daug << it->vardas;
        for(int j=0; j<8; j++)
        {
            daug << " ";
        }
        daug << it->pavarde;
        for(int j=0; j<9; j++)
        {
            daug << " ";
        }
        daug << it->Galutinis << "  ";
        daug << it->mediana <<std::endl;
    }
    it++;
    }
}
void nuskaitymas(int studSk, std::deque<mokinys>& B, std::vector<mokinys> A){
    std::ifstream ifs("Sarasas.txt");
    std::string laik;
    A.resize(studSk);
    double laikd;
    for(int i=0; i < A.size(); i++)
    {
        ifs >> laik;
        A[i].vardas = laik;
        ifs >> laik;
        A[i].pavarde = laik;
        ifs >> laikd;
        A[i].Galutinis = laikd;
        ifs >> laikd;

        A[i].mediana = laikd;
        B.push_back(A[i]);
    }
    ifs.close();
}
#endif

