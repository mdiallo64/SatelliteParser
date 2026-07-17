#ifndef SATELLITE_H
#define SATELLITE_H

#include <string>
#include <iostream>

//Gravitational parameter of earth
constexpr double GP{ 3.986e14 }; //m^3/ s^2
constexpr double PI{ 3.14159265359 };
constexpr double EARTHRADIUS{ 6371 }; //km


class Satellite
{
public:
	Satellite(std::string name, std::string catalogNum, double inclination, double eccentricity, double meanMotion);


	double computePeriod() const;


	double computeSemiMajorAxis() const;

	
	double computeAltitude() const;


	enum class OrbitRegime { LEO, MEO, GEO };


	OrbitRegime calcRegime() const;

	void showSat() const;

	
	std::string getName() const;
	std::string getCatalogNum() const;
	double getInclination() const;
	double getEccentricity() const;
	double getMeanMotion() const;

private:

	std::string m_name{};
	std::string m_catalogNum{};
	double m_inclination{};
	double m_eccentricity{};
	double m_meanMotion{};

};

std::string toString(const Satellite::OrbitRegime orbitRegime);



#endif