#ifndef PARSEINPUT_H
#define PARSEINPUT_H

#include <vector>
#include <functional>
#include "Satellite.h"


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


	void printMenu();

	void getInput(const std::vector<Satellite>& satellites);

	
};

#endif