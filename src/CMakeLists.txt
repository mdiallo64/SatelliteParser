add_library(satlib
    Satellite.cpp
    TLEParser.cpp
    Commands.cpp
    ParseInput.cpp
    StringUtils.cpp
)
target_include_directories(satlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(SatelliteParser main.cpp)
target_link_libraries(SatelliteParser PRIVATE satlib)