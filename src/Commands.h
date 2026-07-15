#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Satellite.h"
#include "StringUtils.h"
#include <string_view>

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
			std::cout << satellite.getName() << ": " << satellite.getCatalogNum() << '\n';
		}

	}


	void searchByName(const std::vector<Satellite>& satellites)
	{
		bool notFound{ true };
		std::cout << "Enter satellite name or enter to show all\n\n";
		std::cout << ">> ";

		std::string satellite{};
		std::getline(std::cin, satellite);

		std::string original{ satellite }; //to print original string if not found
		StringUtils::cleanInput(satellite);

		std::string satName{};

		for (auto& s : satellites)
		{
			satName = s.getName();
			StringUtils::removeChar(satName);
			auto pos{ satName.find(satellite) };
			if (pos != std::string::npos)
			{
				s.showSat();
				notFound = false;
			}
		}
		if (notFound)
		{
			std::cout << "No satellite named " << original << " found\n\n";
		}
	}
}
#endif