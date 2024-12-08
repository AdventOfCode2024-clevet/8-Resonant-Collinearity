cmake_minimum_required(VERSION 3.10)
project(ResonantCollinearity)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Main.cpp
)

set(HEADERS)

add_executable(ResonantCollinearity ${SOURCES} ${HEADERS})
