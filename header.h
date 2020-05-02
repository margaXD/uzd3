#include <iostream>
#include <string>
#include <vector>


class Stud
{
private:
	std::string vardas;
	std::string pavarde;
	std::vector<int> nd;
	int egzas;
	double galvid;
public:
	Stud();
	Stud(std::string, std::string, std::vector<int>, int, double);
	Stud(std::string, std::string, double);
	Stud(std::string, std::string, int);
	~Stud();
	std::string Vardas() const;
	std::string Pavarde() const;
	double Egzas() const;
	double Galutinis() const;
    friend std::istream& operator >> (Stud& s, std::istream& ifst)
    {
		ifst >> s.vardas >> s.pavarde;
		ifst >> s.egzas;
        return ifst;
    }
    bool operator == (const Stud& s)
    {
        return (vardas == s.Vardas() && pavarde == s.Pavarde());
    }
    bool operator != (const Stud& s)
    {
        return !(*this == s);
    }

};
