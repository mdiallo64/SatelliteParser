#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Satellite.h"
#include "StringUtils.h"

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

	void filterLEO(const std::vector<Satellite>& satellites)
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


	void filterMEO(const std::vector<Satellite>& satellites)
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

	void filterGEO(const std::vector<Satellite>& satellites)
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

	void filterCatNum(const std::vector<Satellite>& satellites)
	{
		for (auto& satellite : satellites)
		{
			std::cout << satellite.getCatalogNum() << '\n';
		}

	}


	void searchByName(const std::vector<Satellite>& satellites, std::string& satellite)
	{
	//	if (std::find(satellites.begin(), satellites.end(), satellite) != satellite.end())
	//	{
	//		std::cout << "Found\n";
	//	}
	//	else
	//	{
	//		std::cout << "Not found\n";
	//	}

		for (auto& s : satellites)
		{
			if (s.getName() == StringUtils::cleanInput(satellite))
			{
				std::cout << satellite << '\n';
			}
		}
	}

}
#endif