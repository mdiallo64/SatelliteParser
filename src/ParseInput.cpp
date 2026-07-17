#include "ParseInput.h"
#include "StringUtils.h"
#include <unordered_map>
#include "Commands.h"
#include <iostream>

namespace User
{


	void printMenu(States& currentState)//what user sees based off current state
	{
		if (currentState == Main)
		{
			std::cout << "Commands: list | filter | search | quit\n\n";

		}
		else if (currentState == Filter)
		{
			std::cout << "Filter By: LEO | MEO | GEO | catalog | back | quit\n\n";
		}
	}

	void getInput(const std::vector<Satellite>& satellites)
	{
		States currentState = Main;
		std::string userCommand{};

		//outer map consists of state and another map
		//inner map is the command which gets map to transition struct
		std::unordered_map<User::States, std::unordered_map<std::string, Transition>> fsm;
		fsm[States::Main]["list"] = { Main, Commands::List };
		fsm[States::Main]["filter"] = { Filter, nullptr }; //nullptr for when no action is done
		fsm[States::Main]["search"] = { Main, Commands::searchByName };
		fsm[States::Filter]["leo"] = { Filter, [](auto& s) {Commands::filterbyRegime(s, "LEO"); } };
		fsm[States::Filter]["meo"] = { Filter, [](auto& s) {Commands::filterbyRegime(s, "MEO"); } };
		fsm[States::Filter]["geo"] = { Filter, [](auto& s) {Commands::filterbyRegime(s, "GEO"); } };
		fsm[States::Filter]["catalog"] = { Filter, { Commands::filterCatNum } };
		fsm[States::Filter]["back"] = { Main, nullptr };


		while (true)
		{
			printMenu(currentState);

			std::cout << "Enter Command >> ";
			std::getline(std::cin, userCommand);
			StringUtils::cleanInput(userCommand);
			std::cout << '\n';
			if (userCommand == "quit") break;

			//gets the current state to access user input in inner map
			auto& commandsForState = fsm[currentState];
			auto it = commandsForState.find(userCommand); //get iterator to point to key position in map, if not found the iterator = end()
			if (it != commandsForState.end())//not equal to end ^
			{
				if (it->second.action)
				{
					it->second.action(satellites);//calling std::function in Transition struct with satellite argument
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