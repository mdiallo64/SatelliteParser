#ifndef PARSEINPUT_H
#define PARSEINPUT_H

#include "Commands.h"
#include <vector>
#include <unordered_map>
#include <functional>
#include "Satellite.h"
#include "StringUtils.h"

namespace User
{

	enum States
	{
		Main,
		Filter,
		Search
	};

	struct Transition
	{
		//next state based off what user types
		States next{};
		//function that gets called based off value of map
		std::function<void(const std::vector<Satellite>&)> action{};
	};



	States currentState = Main;


	void printMenu()//what user sees based off current state
	{
		if (currentState == Main)
		{
			std::cout << "Commands: List | Filter | Search\n\n";
			std::cout << "Quit\n\n\n";
		}
		else if (currentState == Filter)
		{
			std::cout << "Filter By: LEO | MEO | GEO | catalogNum\n\n";
			std::cout << "Back | Quit\n\n\n";
			std::cout << "--------------------------------\n";
		}	
	}

	void getInput(const std::vector<Satellite>& satellites)
	{
		std::string userCommand{};

		//outer map consists of state and another map
		//inner map is the command which gets map to transition struct
		std::unordered_map<User::States, std::unordered_map<std::string, Transition>> fsm;
		fsm[States::Main]["list"] = { Main, Commands::List };
		fsm[States::Main]["filter"] = { Filter, nullptr }; //nullptr for when no action is done
		fsm[States::Main]["search"] = { Main, Commands::searchByName };
		fsm[States::Filter]["leo"] = { Filter, Commands::filterLEO };
		fsm[States::Filter]["meo"] = { Filter, Commands::filterMEO };
		fsm[States::Filter]["geo"] = { Filter, Commands::filterGEO };
		fsm[States::Filter]["catalog"] = { Filter, Commands::filterCatNum };
		fsm[States::Filter]["back"] = { Main, nullptr };
		//fsm[States::Search]["search"] = { Search, nullptr};



		while (true)
		{
			printMenu();

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

#endif