#include <iostream>
#include <fstream>
#include "Satellite.h"
#include "TLEParser.h"
#include "ParseInput.h"
#include <format>

int main()
{
	std::vector<Satellite> satellites = TLEParser::getData("src/data/data.txt");


	User::getInput(satellites);

	return 0;
}