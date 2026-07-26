#include <iostream>
#include <fstream>
#include "Satellite.h"
#include "TLEParser.h"
#include "ParseInput.h"
#include <format>

int main(int argc, char* argv[])
{

	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <path-to-tle-file>\n"; //usage line
		return 1;
	}
	std::vector<Satellite> satellites = TLEParser::getData(argv[1]);


	std::cout << "TLE Satellite Parser\n\n";
	std::cout << satellites.size() << " Satellites loaded\n";
	std::cout << "\n";


	User::getInput(satellites);

	return 0;
}