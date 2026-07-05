#include <iostream>
#include <fstream>
#include "Satellite.h"
#include <vector>
#include "TLEParser.h"

int main()
{
	
	TLEParser::getData("src/data/data.txt");
	return 0;
}