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
	void printHeader()
	{
		std::cout << std::format("{:<25}", "Name");
		std::cout << std::format("{:<20}", "Catalog Number");
		std::cout << std::format("{:<18}", "Inclination");
		std::cout << std::format("{:<21}", "Eccentricity");
		std::cout << std::format("{:<20}", "Mean Motion");
		std::cout << '\n';
	}
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
		std::vector<Satellite> s{};
		bool notFound{ true };
		for (auto& satellite : satellites)
		{
			std::string orbType = satellite.toString(satellite.calcRegime());
			if (orbType == "LEO")
			{
				s.push_back(satellite);
				notFound = false;
			}			
		}
		if (!notFound)
		{
			printHeader();
			for (auto& sat : s)
			{
				sat.Satellite::showSat();
			}
		}
		else
		{
			std::cout << "No LEO satellites found";
		}
		std::cout << '\n';
	}




	void filterMEO(const std::vector<Satellite>& satellites)
	{
		std::cout << "Current filter applied: MEO\n";
		std::vector<Satellite> s{};
		bool notFound{ true };
		for (auto& satellite : satellites)
		{
			std::string orbType = satellite.toString(satellite.calcRegime());
			if (orbType == "MEO")
			{
				s.push_back(satellite);
				notFound = false;
			}
		}
		if (!notFound)
		{
			printHeader();
			for (auto& sat : s)
			{
				sat.Satellite::showSat();
			}

		}
		else
		{
			std::cout << "No MEO satellites found";
		}
		std::cout << '\n';
	}

	void filterGEO(const std::vector<Satellite>& satellites)
	{
		std::cout << "Current filter applied: GEO\n";
		std::vector<Satellite> s{};
		bool notFound{ true };
		for (auto& satellite : satellites)
		{
			std::string orbType = satellite.toString(satellite.calcRegime());
			if (orbType == "GEO")
			{
				s.push_back(satellite);
				notFound = false;
			}
		}
		if (!notFound)
		{
			printHeader();
			for (auto& sat : s)
			{
				sat.Satellite::showSat();
				std::cout << '\n';
			}
		}
		else
		{
			std::cout << "No GEO satellites found";
		}
		std::cout << '\n';
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