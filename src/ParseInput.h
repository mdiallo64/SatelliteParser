#ifndef PARSEINPUT_H
#define PARSEINPUT_H

#include "Commands.h"
#include <vector>
#include <unordered_map>
#include <functional>
#include "Satellite.h"
#include <cctype>
#include <algorithm>

namespace User
{

	std::string cleanInput(std::string& input)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		return input;
	}

	void getInput(const std::vector<Satellite>& satellites)
	{
		std::string userCommand{};
		std::unordered_map<std::string, std::function<void(std::vector<Satellite>)>> commands;
		commands["list"] = Commands::List;
		commands["filter"] = Commands::Filter;

		while (true)
		{
			std::cout << "Commands: List	Filter\n";

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
				std::cout << "Command not found\n";
			}

		}
	}
};

#endif