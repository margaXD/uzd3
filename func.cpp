#ifndef FUNC.CPP
#define FUNC.CPP
#include <string>
#include <vector>
#include "head.h"
struct mokinys{
    std::string vardas;
    std::string pavarde;
    double vidurkisvec;
    double medianavec;
};
void xDbandymas(char xD){}
void rusiavimas(std::vector<std::string> &vardas, std::vector<std::string> &pavarde, std::vector<double> &vidurkisvec, std::vector<double> &medianavec)
{
        for(int i=0; i<pavarde.size(); i++)
        {
        std::string tempV;
        std::string tempP;
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
}
#endif
