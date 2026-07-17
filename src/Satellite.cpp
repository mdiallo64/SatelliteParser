
#include "Satellite.h"
#include <iostream>
#include <cmath>
#include <format>


	Satellite::Satellite(std::string name, std::string catalogNum, double inclination, double eccentricity, double meanMotion)
		: m_name{ name }
		, m_catalogNum{ catalogNum }
		, m_inclination{ inclination }
		, m_eccentricity{ eccentricity }
		, m_meanMotion{ meanMotion }
	{
	}

	double Satellite::computePeriod() const
	{
		return (1 / m_meanMotion) * 1440; //1440 = minutes per day
	}

	double Satellite::computeSemiMajorAxis() const
	{
		double T{ computePeriod() * 60 };
		return std::cbrt(GP * T * T / (4 * PI * PI)) / 1000; //formula for orbital period
	}

	double Satellite::computeAltitude() const
	{
		return computeSemiMajorAxis() - EARTHRADIUS;
	}



	Satellite::OrbitRegime Satellite::calcRegime() const
	{
		double altitude{ computeAltitude() };
		if (altitude < 2000)
		{
			return OrbitRegime::LEO;
		}
		else if (altitude < 35786)
		{
			return OrbitRegime::MEO;
		}
		else
			return OrbitRegime::GEO;
	}


	void Satellite::showSat() const
	{
		std::cout << std::format("{:<25}", m_name);
		std::cout << std::format("{:<20}", m_catalogNum);
		std::cout << std::format("{:<18}", m_inclination);
		std::cout << std::format("{:<18}", toString(calcRegime()));
		std::cout << std::format("{:<18.2f}", computePeriod());
		std::cout << std::format("{:<18.2f}", computeAltitude());
		std::cout << std::format("{:<21}", m_eccentricity);
		std::cout << std::format("{:<15.2f}", m_meanMotion) << '\n';
		std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << '\n';


	}
	std::string Satellite::getName() const { return m_name; }
	std::string Satellite::getCatalogNum() const { return m_catalogNum; }
	double Satellite::getInclination() const { return m_inclination; }
	double Satellite::getEccentricity() const { return m_eccentricity; }
	double Satellite::getMeanMotion() const { return m_meanMotion; }





std::string toString(const Satellite::OrbitRegime orbitRegime)
{
	std::string result{};

	switch (orbitRegime)
	{
	case Satellite::OrbitRegime::LEO:
		return "LEO";

	case Satellite::OrbitRegime::MEO:
		return "MEO";

	case Satellite::OrbitRegime::GEO:
		return "GEO";
	}
	return "Unknown";
}


