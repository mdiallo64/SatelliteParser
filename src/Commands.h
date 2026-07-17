#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include "Satellite.h"
#include "StringUtils.h"

namespace Commands
{
	void printHeader();

	void List(const std::vector<Satellite>& satellites);


	void filterbyRegime(const std::vector<Satellite>& satellites, const std::string regime);


	void filterCatNum(const std::vector<Satellite>& satellites);



	void searchByName(const std::vector<Satellite>& satellites);

}
#endif