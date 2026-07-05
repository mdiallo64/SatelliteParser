#ifndef TLEPARSER_H
#define TLEPARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Satellite.h"

namespace TLEParser
{
	std::vector<Satellite> getData(std::string path)
	{
		std::ifstream input{path};

		if (!input)
		{
			std::cerr << "Could not open file\n";
			return {};
		}
		std::string data{};

		//where each satellite object will be stored
		std::vector<Satellite> satellites;

		//while there's still things left to be read
		while (std::getline(input, data))
		{
			//Get satellite name and move to next line
			std::string name{};
			name = data;
			std::cout << "Name: " << name << '\n';

			//Reads the entire line into data variable
			//Since TLE files have fixed position, can always skip to position 2 for catalog num
			std::getline(input, data);
			std::string catNum = data.substr(2, 5);
			std::cout << "Catalog number: " << catNum << '\n';

			std::getline(input, data);
			double inclination = std::stod(data.substr(8, 8)); //converts from string to double for math purposes
			std::cout << "Inclination:" << inclination << '\n';


	
			std::string temp = data.substr(26, 7);
			temp.insert(0, "0.");
			double eccentricity = std::stod(temp);
			std::cout << "Eccentricity: " << eccentricity << '\n';

			double meanMotion = std::stod(data.substr(52, 11));
			std::cout << "Mean motion: " << meanMotion << '\n' << '\n';

			//each time a satellite is read, it is added to a vector
			satellites.emplace_back(name, catNum, inclination, eccentricity, meanMotion);
		}
		return satellites;
	}
}
#endif