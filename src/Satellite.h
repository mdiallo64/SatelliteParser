#ifndef SATELLITE_H
#define SATELLITE_H

#include <string>
#include <iostream>
#include <cmath>
#include <format>

//Gravitational parameter of earth
constexpr double GP{ 3.986e14 }; //m^3/ s^2
constexpr double PI{ 3.14159265359 };
constexpr double EARTHRADIUS{ 6371 }; //km


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

	double computePeriod() const
	{
		return (1 / m_meanMotion) * 1440; //1440 = minutes per day
	}

	double computeSemiMajorAxis() const
	{
		double T{ computePeriod() * 60 };
		return std::cbrt(GP * T * T / (4 * PI * PI)) / 1000; //formula for orbital period
	}
	
	double computeAltitude() const
	{
		return computeSemiMajorAxis() - EARTHRADIUS;
	}

	enum class OrbitRegime { LEO, MEO, GEO };

	OrbitRegime calcRegime() const
	{
		double altitude{ computeAltitude() };
		if (altitude < 2000)
		{
			return OrbitRegime::LEO;
		}
		else if(altitude < 35786)
		{
			return OrbitRegime::MEO;
		}
		else
			return OrbitRegime::GEO;
	}

	std::string toString(const OrbitRegime orbitRegime) const
	{
		std::string result{};

		switch (orbitRegime)
		{
		case OrbitRegime::LEO: 
			return "LEO";
		
		case OrbitRegime::MEO:
			return "MEO";

		case OrbitRegime::GEO:
			return "GEO";
		}
		return "Unknown";
	}

	void showSat() const
	{
		std::cout << std::format("{:>16}", "Name: ") << m_name << " \n";
		std::cout << "Catalog Number: " << m_catalogNum << " \n";
		std::cout << std::format("{:>16}", "Inclination: ") << m_inclination << " \n";
		std::cout << std::format("{:>16}", "Eccentricity: ") << m_eccentricity << " \n";
		std::cout << std::format("{:>16}", "Mean Motion: ") << m_meanMotion << " \n";
		std::cout << "----------------------------\n\n\n";

	}
	std::string getName() const { return m_name; }
	std::string getCatalogNum() const { return m_catalogNum; }
	double getInclination() const { return m_inclination; }
	double getEccentricity() const { return m_eccentricity; }
	double getMeanMotion() const { return m_meanMotion; }

private:

	std::string m_name{};
	std::string m_catalogNum{};
	double m_inclination{};
	double m_eccentricity{};
	double m_meanMotion{};

};


#endif