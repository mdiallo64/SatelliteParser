#ifndef SATELLITE_H
#define SATELLITE_H

#include <string>
#include <iostream>
class Satellite
{
public:
	Satellite(std::string name,std::string catalogNum, double inclination, double eccentricity, double meanMotion) 
		: m_name{name}
		, m_catalogNum{catalogNum}
		, m_inclination{inclination}
		, m_eccentricity{eccentricity}
		, m_meanMotion{meanMotion}
	{}
private:

	std::string m_name{};
	std::string m_catalogNum{};
	double m_inclination{};
	double m_eccentricity{};
	double m_meanMotion{};
};


#endif