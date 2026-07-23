#include <gtest/gtest.h>
#include "Satellite.h"

TEST(SatelliteMath, IssPeriodIsAboutNinetyThreeMinutes)
{
    Satellite iss{ "ISS (ZARYA)", "25544", 51.631, 0.0006717, 15.49 };
    EXPECT_NEAR(iss.computePeriod(), 92.96, 0.1);
}