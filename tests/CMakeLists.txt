add_executable(SatelliteTests test_satellite.cpp)
target_link_libraries(SatelliteTests PRIVATE gtest_main satlib)
include(GoogleTest)
gtest_discover_tests(SatelliteTests)