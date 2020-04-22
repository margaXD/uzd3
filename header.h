#include <iostream>
#include <string>
#include <vector>


class Stud
{
	public:
		Stud();
		Stud(std::string, std::string, std::vector<int>, int, double);
		Stud(std::string, std::string, double);
		~Stud();
		std::string Vardas() const;
		std::string Pavarde() const;
		double Egzas() const;
		double Galutinis() const;
	private:
		std::string vardas;
		std::string pavarde;
		std::vector<int> nd;
		int egzas;
		double galvid;
};
