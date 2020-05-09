#include "head.h"


int main()
{
	int s = pradzia();
	if (s == 3)
	{
		ofstream fr("Container.txt");
		int Vvardas = 8, Ppavarde = 9;
		/*vector<Stud>StudentaiV;
		vector<Stud>errorV;
		vector<Stud>NeroV;*/
		list<Stud>StudentaiL;
		list<Stud>errorL;
		list<Stud>NeroL;
		/*deque<Stud>StudentaiD;
		deque<Stud>errorD;
		deque<Stud>NeroD;*/
		for (int i = 0; i < 2; i++)
		{
			/*if (i == 0)fr << "Konteineriams prireike tiek laiko:" << endl;
			else fr << "Skirstant i konteinerius:" << endl;
			auto begin = std::chrono::high_resolution_clock::now();
			nuskaitymas(StudentaiV, Vvardas, Ppavarde);
			auto end = std::chrono::high_resolution_clock::now();
			fr << "Nuskaitymui i vectoriu prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			begin = std::chrono::high_resolution_clock::now();
			if (i == 0)rusiavimas(StudentaiV, errorV);
			else rusiavimas2(StudentaiV, errorV, NeroV);
			end = std::chrono::high_resolution_clock::now();
			fr << "Vektoriu rusiavimui prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			begin = std::chrono::high_resolution_clock::now();
			if (i == 0)spausdinimas(StudentaiV, Vvardas, Ppavarde, "Vektoriniai Studentai");
			else spausdinimas(NeroV, Vvardas, Ppavarde, "Vektoriniai Kietiekai");
			spausdinimas(errorV, Vvardas, Ppavarde, "Vektoriniai Vargsiukai");
			end = std::chrono::high_resolution_clock::now();
			fr << "Duomenims, esantiems vektoriuje, isvesti prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			StudentaiV.clear();
			errorV.clear();
			NeroV.clear();*/
			auto begin = std::chrono::high_resolution_clock::now();
			nuskaitymas(StudentaiL, Vvardas, Ppavarde);
			auto end = std::chrono::high_resolution_clock::now();
			fr << "Nuskaitymui i lista prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			begin = std::chrono::high_resolution_clock::now();
			if (i == 0)rusiavimasL(StudentaiL, errorL);
			else rusiavimasL2(StudentaiL, errorL, NeroL);
			end = std::chrono::high_resolution_clock::now();
			fr << "Duomenu esanciu liste skirstymui prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			begin = std::chrono::high_resolution_clock::now();
			//if (i == 0)spausdinimas(StudentaiL, Vvardas, Ppavarde, "List Studentai");
			//else spausdinimas(NeroL, Vvardas, Ppavarde, "List Kietiakai");
			spausdinimas(errorL, Vvardas, Ppavarde, "List Vergsiukai");
			end = std::chrono::high_resolution_clock::now();
			fr << "Duomenims esantiems liste isvesti prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			StudentaiL.clear();
			errorL.clear();
			NeroL.clear();/*
			begin = std::chrono::high_resolution_clock::now();
			nuskaitymas(StudentaiD, Vvardas, Ppavarde);
			end = std::chrono::high_resolution_clock::now();
			fr << "Nuskaitant duomenis i deque prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			begin = std::chrono::high_resolution_clock::now();
			if (i == 0)rusiavimas(StudentaiD, errorD);
			else rusiavimas2(StudentaiD, errorD, NeroD);
			end = std::chrono::high_resolution_clock::now();
			fr << "Duomenims esantiems deque isskirstymui prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			if (i == 0)spausdinimas(StudentaiD, Vvardas, Ppavarde, "DequeKietiakai");
			else spausdinimas(NeroD, Vvardas, Ppavarde, "DequeKietiakai");
			spausdinimas(errorD, Vvardas, Ppavarde, "DequeFeilai");
			end = std::chrono::high_resolution_clock::now();
			fr << "Deque prireike " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << endl;
			NeroD.clear();
			errorD.clear();
			StudentaiD.clear();*/
		}
		fr.close();
	}
	return 0;
}
