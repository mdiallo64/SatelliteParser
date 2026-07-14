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

	struct Transition
	{
		States next{};
		std::function<void(const std::vector<Satellite>&)> action{};
	};

	States currentState = Main;

	std::string cleanInput(std::string& input)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		return input;
	}

	void printMenu()
	{
		if (currentState == Main)
		{
			std::cout << "Commands: List	Filter\n";
		}
		else if (currentState == Filter)
		{
			std::cout << "Filter by LEO MEO GEO all \n";
		}
		else
		{

		}
	}

	void getInput(const std::vector<Satellite>& satellites)
	{
		std::string userCommand{};

		std::unordered_map<User::States, std::unordered_map<std::string, Transition>> fsm;
		fsm[States::Main]["list"] = { Main, Commands::List };
		fsm[States::Main]["filter"] = { Filter, nullptr };
		fsm[States::Filter]["leo"] = { Filter, Commands::Filter };



		while (true)
		{
			printMenu();

			std::cout << ">> ";
			std::getline(std::cin, userCommand);
			cleanInput(userCommand);

			auto& commandsForState = fsm[currentState];
			auto it = commandsForState.find(userCommand);
			if (it != commandsForState.end())
			{
				if (it->second.action)
				{
					it->second.action(satellites);
				}
				currentState = it->second.next;

			}
			else
			{
				std::cout << "Command not found\n";
			}
		}
	}


	
};

#endif