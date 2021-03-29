#include <iostream>
#include "main.h"

vector<Substance> getCachedSubstances() {
	vector<Substance> list = {
		Substance{"Tin", 118.71, "Conductor" },
		Substance{"Fermium", 257, "Conductor" },
		Substance{"Copper", 63.55, "Conductor" },
		Substance{"Gold", 196.97, "Conductor" },
		Substance{"Oil", -1, "Insulator" },
		Substance{"Glass", -1, "Insulator" },
		Substance{"Plastic", -1, "Insulator" },
		Substance{"Paper", -1, "Insulator" },
		Substance{"Pure water", -1, "Insulator" },
		Substance{"Silicon", 28.09, "Semiconductor" },
		Substance{"Selenium", 78.96, "Semiconductor" },
		Substance{"Iodine", 126.9, "Semiconductor" },
		Substance{"Germanium", 72.63, "Semiconductor" },
	};

	return list;
}

vector<Substance> findSubstances(
	vector<Substance> substances, 
	string compareTo, 
	string searchType) 
{
	vector<Substance> list; 
	for(int i = 0; i < substances.size(); i++)
	{
		Substance substance = substances.at(i);
		if(searchType == "n")
			if (substance.name == compareTo)
				list.push_back(substance);

		if (searchType == "m")
			if (substance.mass == stod(compareTo))
				list.push_back(substance);

		if (searchType == "c")
			if (substance.conductivity == compareTo)
				list.push_back(substance);
	}

	return list;
}