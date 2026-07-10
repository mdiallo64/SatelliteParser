#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <vector>
#include "Satellite.h"

namespace Commands
{
	void List(const std::vector<Satellite>& satellites)
	{
		for (auto& satellite : satellites)
		{
			std::cout << satellite.getName() << '\n';
			std::cout << satellite.getCatalogNum() << '\n';
			std::cout << satellite.getInclination() << '\n';
			std::cout << satellite.getEccentricity() << '\n';
			std::cout << satellite.getMeanMotion() << '\n';
			std::cout << '\n';
		}
	}
}
#endif