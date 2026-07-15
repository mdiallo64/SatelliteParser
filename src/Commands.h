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
			/*std::cout << satellite.getCatalogNum() << '\n';
			std::cout << satellite.getInclination() << '\n';
			std::cout << satellite.getEccentricity() << '\n';
			std::cout << satellite.getMeanMotion() << '\n';
			std::cout << '\n';*/
		}
		std::cout << '\n';
	}

	void FilterLEO(const std::vector<Satellite>& satellites)
	{
		std::cout << "Current filter applied: LEO\n";
		for (auto& satellite : satellites)
		{
			std::string orbType = satellite.toString(satellite.calcRegime());
			if (orbType != "LEO")
			{
				std::cout << "No LEO satellites in found\n";
				break;
			}
			else
			{
				std::cout << satellite.getName() << '\n';
				//std::cout << orbType << '\n';
			}
		}
	}


	void FilterMEO(const std::vector<Satellite>& satellites)
	{

		for (auto& satellite : satellites)
		{
			std::string orbType = satellite.toString(satellite.calcRegime());
			if (orbType != "MEO")
			{
				std::cout << "No MEO satellites in found\n";
				break;
			}
			else
			{
				std::cout << satellite.getName();
				std::cout << orbType << '\n';
			}
		}
	}

	void FilterGEO(const std::vector<Satellite>& satellites)
	{
		for (auto& satellite : satellites)
		{
			std::string orbType = satellite.toString(satellite.calcRegime());
			if (orbType != "GEO")
			{
				std::cout << "No GEO satellites in found\n";
				break;
			}
			else
			{
				std::cout << satellite.getName();
				std::cout << orbType << '\n';
			}
		}
	}

	void FilterCatNum(const std::vector<Satellite>& satellites)
	{
		for (auto& satellite : satellites)
		{
			std::cout << satellite.getCatalogNum() << '\n';
		}

	}


}
#endif