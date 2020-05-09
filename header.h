#include <iostream>
#include <string>
#include <vector>
class base
{
	protected:
		std::string vardas;
		std::string pavarde;
		base (std::string Bvardas = " ", std::string Bpavarde = " ") : vardas{Bvardas}, pavarde{Bpavarde} { }
	public:
		virtual std::string Vardas() const { return vardas; }
		virtual std::string Pavarde() const { return pavarde; }
};

class Stud : public base
{
private:
	std::vector<int> nd;
	int egzas;
	double galvid;
public:
	Stud(std::string Bvardas = " ", std::string Bpavarde = " ", int rez = 0) : base{Bvardas, Bpavarde}, egzas{rez} { }
	Stud();
	Stud(std::string, std::string, std::vector<int>, int, double);
	Stud(std::string, std::string, double);
	double Egzas() const;
	double Galutinis() const;
    /*friend std::istream& operator >> (Stud& s, std::istream& ifst)
    {
		ifst >> s.vardas >> s.pavarde;
		ifst >> s.egzas;
        return ifst;
    }*/
    bool operator == (const Stud& s)
    {
        return (vardas == s.Vardas() && pavarde == s.Pavarde());
    }
    bool operator != (const Stud& s)
    {
        return !(*this == s);
    }

};
