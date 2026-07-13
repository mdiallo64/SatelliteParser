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

	enum States
	{
		Main,
		Filter
	};

	States currentState = Main;

	std::string cleanInput(std::string& input)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		return input;
	}

	void changeState()
	{
		if (currentState == Main)
		{
			std::cout << "Commands: List	Filter\n";
		}
		else if (currentState == Filter)
		{
			std::cout << "Filter menu \n";
		}
		else
		{

		}
	}


	void getInput(const std::vector<Satellite>& satellites)
	{
		std::string userCommand{};

		std::unordered_map<std::string, std::unordered_map<User::States, std::function<void(std::vector<Satellite>)>>> commands;
		commands["list"][States::Main] =  Commands::List;
		commands["filter"][States::Main] = Commands::Filter;
		changeState();

		while (true)
		{

			std::cout << ">> ";
			std::getline(std::cin, userCommand);
			cleanInput(userCommand);

			auto it = commands.find(userCommand);
			if (it != commands.end())
			{
				auto stateMap = it->second;

				auto stateIt = stateMap.find(currentState);
				if (stateIt != stateMap.end())
				{
					stateIt->second(satellites);
				}
				else
				{
					std::cout << "Command not found";
				}
			}
		}
	}


	
};

#endif