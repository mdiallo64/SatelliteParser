add_executable(SatelliteTests test_satellite.cpp)
add_custom_command(TARGET SatelliteTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/test_data.txt"
        "$<TARGET_FILE_DIR:SatelliteTests>/test_data.txt")
target_link_libraries(SatelliteTests PRIVATE gtest_main satlib)
include(GoogleTest)
gtest_discover_tests(SatelliteTests)