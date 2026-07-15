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
		//next state based off what user types
		States next{};
		//function that gets called based off value of map
		std::function<void(const std::vector<Satellite>&)> action{};
	};

	States currentState = Main;


	std::string cleanInput(std::string& input)//removes whitespace and turns user input lowercase to match map key
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		return input;
	}

	void printMenu()//what user sees based off current state
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

		//outer map consists of state and another map
		//inner map is the command which gets map to transition struct
		std::unordered_map<User::States, std::unordered_map<std::string, Transition>> fsm;
		fsm[States::Main]["list"] = { Main, Commands::List };
		fsm[States::Main]["filter"] = { Filter, nullptr }; //nullptr for when no action is done
		fsm[States::Filter]["leo"] = { Filter, Commands::Filter };



		while (true)
		{
			printMenu();

			std::cout << ">> ";
			std::getline(std::cin, userCommand);
			cleanInput(userCommand);

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