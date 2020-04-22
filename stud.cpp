#include "header.h"

using std::string;

Stud::Stud()
{
	egzas = 0;
	galvid = 0.0;
}

Stud::Stud(string vardas1, string pavarde1, std::vector<int> pz, int egz, double gal)
{
	vardas = vardas1;
	pavarde = pavarde1;
	nd.reserve(pz.size());
	copy(pz.begin(), pz.end(), back_inserter(nd));
	egzas = egz;
	galvid = gal;
}

Stud::Stud(string vardas1, string pavarde1, double gal)
{
	vardas = vardas1;
	pavarde = pavarde1;
	egzas = 0;
	galvid = gal;
}

Stud::~Stud()
{
}

string Stud::Vardas() const
{
	return vardas;
}

string Stud::Pavarde() const
{
	return pavarde;
}

double Stud::Egzas() const
{
	return egzas;
}

double Stud::Galutinis() const
{
	return galvid;
}
