#include <iostream>
#include <fstream>
#include "Satellite.h"
#include <vector>
#include "TLEParser.h"
#include "Commands.h"
#include <unordered_map>
#include <functional>
#include <cctype>
#include <algorithm>



std::string cleanInput(std::string& input)
{
	input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	return input;
}


int main()
{
	std::vector<Satellite> satellites = TLEParser::getData("src/data/data.txt");

	std::string userCommand{};
	std::unordered_map<std::string, std::function<void(std::vector<Satellite>)>> commands;
	commands["list"] = Commands::List;

	while (true)
	{
		std::cout << "Commands: List\n";

		std::cout << ">> ";
		std::getline(std::cin, userCommand);
		cleanInput(userCommand);

		auto it = commands.find(userCommand);
		if (it != commands.end())
		{
			it->second(satellites);
		}
		else
		{
			std::cout << "Command not found";
		}

	}

	//for (auto& satellite : satellites)
	//{
	//	std::cout << satellite.computePeriod() << '\n';
	//	std::cout << satellite.computeSemiMajorAxis() << '\n';
	//	std::cout << satellite.computeAltitude() << '\n';
 //	}
	return 0;
}