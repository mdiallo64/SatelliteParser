
#include "TLEParser.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Satellite.h"


namespace TLEParser
{
	std::vector<Satellite> getData(std::string path)
	{
		std::ifstream input{ path };

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
			name.erase(name.find_last_not_of(" \r") + 1); //removes trailing \r on linux systems


			//Reads the entire line into data variable
			//Since TLE files have fixed position, can always skip to position 2 for catalog num
			std::getline(input, data);
			std::string catNum = data.substr(2, 5);

			std::getline(input, data);
			double inclination = std::stod(data.substr(8, 8)); //converts from string to double for math purposes



			std::string temp = data.substr(26, 7);
			temp.insert(0, "0.");
			double eccentricity = std::stod(temp);

			double meanMotion = std::stod(data.substr(52, 11));


			//constructs and add a satellite to the vector
			satellites.emplace_back(name, catNum, inclination, eccentricity, meanMotion);

		}

		std::cout << "TLE Satellite Parser\n\n";
		std::cout << satellites.size() << " Satellites loaded\n";
		std::cout << "\n";
		return satellites;
	}
}
