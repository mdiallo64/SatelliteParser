#include <iostream>
#include <fstream>
#include "Satellite.h"
#include "TLEParser.h"
#include "ParseInput.h"
#include <format>

int main(int argc, char* argv[])
{
	std::vector<Satellite> satellites = TLEParser::getData(argv[1]);


	User::getInput(satellites);

	return 0;
}