add_executable(SatelliteParser main.cpp Satellite.cpp ParseInput.cpp TLEParser.cpp Commands.cpp StringUtils.cpp "TLEParser.h" "Commands.h" "ParseInput.h" "TLEParser.cpp" "Commands.cpp" "StringUtils.cpp" "Satellite.cpp")
set_property(TARGET SatelliteParser PROPERTY CXX_STANDARD 20)

add_custom_command(TARGET SatelliteParser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/data/data.txt"
        "$<TARGET_FILE_DIR:SatelliteParser>/data/data.txt"
)