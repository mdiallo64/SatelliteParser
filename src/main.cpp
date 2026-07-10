#include <iostream>
#include <fstream>
#include "Satellite.h"
#include "TLEParser.h"
#include "ParseInput.h"


int main()
{
	std::vector<Satellite> satellites = TLEParser::getData("src/data/data.txt");


	User::getInput(satellites);

	//for (auto& satellite : satellites)
	//{
	//	std::cout << satellite.computePeriod() << '\n';
	//	std::cout << satellite.computeSemiMajorAxis() << '\n';
	//	std::cout << satellite.computeAltitude() << '\n';
	//	std::cout << satellite.toString(satellite.calcRegime()) << '\n';
	//	std::cout << '\n';
 //	}
	return 0;
}