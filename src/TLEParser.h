#ifndef TLEPARSER_H
#define TLEPARSER_H

#include <vector>
#include "Satellite.h"
#include <string>

namespace TLEParser
{
	std::vector<Satellite> getData(std::string path);

}
#endif