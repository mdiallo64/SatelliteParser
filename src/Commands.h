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

		}
		std::cout << '\n';
	}

	void filterbyRegime(const std::vector<Satellite>& satellites, const std::string regime)
	{
		std::cout << "Current filter applied: " << regime << " \n";
		bool found{ false };
		for (const auto& satellite : satellites)
		{
			if (toString(satellite.calcRegime()) == regime)
			{
				if (!found)
				{
					printHeader();
					found = true;
				}
				satellite.showSat();
			}


		}
		if (!found)
		{
			std::cout << "No " << regime << " satellites found\n";
		}


	}

	void filterCatNum(const std::vector<Satellite>& satellites)
	{
		std::cout << "Enter catalog number: ";
		std::string catalogNum;
		std::getline(std::cin, catalogNum);
		StringUtils::cleanInput(catalogNum);

		bool found = false;
		for (const auto& satellite : satellites)
		{
			if (satellite.getCatalogNum().find(catalogNum) != std::string::npos)
			{
				if (!found)
				{
					printHeader();
					found = true;
				}
				satellite.showSat();
			}
		}
		if (!found)
		{
			std::cout << "No satellite with catalog number " << catalogNum << " found\n";
		}
	}


	void searchByName(const std::vector<Satellite>& satellites)
	{
		bool found{ false };
		std::cout << "Enter satellite name or enter to show all\n\n";
		std::cout << ">> ";

		std::string satellite{};
		std::getline(std::cin, satellite);

		std::string original{ satellite }; //to print original string if not found
		StringUtils::cleanInput(satellite);

		std::string satName{};

		printHeader();
		for (auto& s : satellites)
		{
			satName = s.getName();
			StringUtils::removeChar(satName);
			auto pos{ satName.find(satellite) };
			if (pos != std::string::npos)
			{
				s.showSat();
				found = true;
			}
		}
		if (!found)
		{
			std::cout << "No satellite named " << original << " found\n\n";
		}
	}
}
#endif