#include <gtest/gtest.h>
#include "Satellite.h"
#include "TLEParser.h"

TEST(SatelliteMath, IssPeriodIsAboutNinetyThreeMinutes)
{
    Satellite iss{ "ISS (ZARYA)", "25544", 51.631, 0.0006717, 15.49 };
    EXPECT_NEAR(iss.computePeriod(), 92.96, 0.1);
}

TEST(SatelliteMath, LowOrbitClassifiesAsLEO)
{
    Satellite iss{ "ISS (ZARYA)", "25544", 51.631, 0.0006717, 15.49 };
    EXPECT_EQ(iss.calcRegime(), Satellite::OrbitRegime::LEO);
}

TEST(SatelliteMath, HighOrbitClassifiesAsGEO)
{
    Satellite ats{ "ATS 3", "03029", 3.2725, 0.0015725, 1.002 };
    EXPECT_EQ(ats.calcRegime(), Satellite::OrbitRegime::GEO);
}

TEST(SatelliteMath, HighOrbitClassifiesAsMEO)
{
    Satellite gps{ "GPS BIII-8  (PRN 21)", "64202", 55.1122, 0.00000064, 2.0057 };
    EXPECT_EQ(gps.calcRegime(), Satellite::OrbitRegime::MEO);
}

TEST(Parser, EccentricityDecodesImplicitDecimal)
{
    auto sats = TLEParser::getData("test_data.txt");

    ASSERT_FALSE(sats.empty());
    EXPECT_EQ(sats[0].getName(), "ISS (ZARYA)");
    EXPECT_NEAR(sats[0].getEccentricity(), 0.0006703, 1e-7);
    EXPECT_NEAR(sats[0].getMeanMotion(), 15.49814080, 1e-6);
}