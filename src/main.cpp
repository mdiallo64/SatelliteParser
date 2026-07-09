#include <iostream>
#include <fstream>
#include "Satellite.h"
#include <vector>
#include "TLEParser.h"
#include "Commands.h"
#include <unordered_map>
#include <functional>
int main()
{
	std::vector<Satellite> satellites = TLEParser::getData("src/data/data.txt");

	for (auto& satellite : satellites)
	{
		std::cout << satellite.computePeriod() << '\n';
		std::cout << satellite.computeSemiMajorAxis() << '\n';
		std::cout << satellite.computeAltitude() << '\n';
 	}
	return 0;
}