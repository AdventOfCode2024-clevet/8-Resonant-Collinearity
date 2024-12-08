cmake_minimum_required(VERSION 3.10)
project(ResonantCollinearity)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Main.cpp
    src/ArgumentParser.cpp
    src/FileReader.cpp
)

set(HEADERS
    src/AntinodeCalculator.hpp
    src/ArgumentParser.hpp
    src/FileReader.hpp
)

add_executable(ResonantCollinearity ${SOURCES} ${HEADERS})
