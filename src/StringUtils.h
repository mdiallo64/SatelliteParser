#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <algorithm>
#include <cctype>


namespace StringUtils
{
	std::string cleanInput(std::string& input)//removes whitespace and turns user input lowercase to match map key
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		return input;
	}

	std::string removeChar(std::string& input)//removes whitespace and turns user input lowercase to match map key
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		std::erase(input, '(');
		std::erase(input, ')');
		return input;
	}

	
}


#endif