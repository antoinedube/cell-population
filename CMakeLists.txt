cmake_minimum_required (VERSION 2.8)

project (SimulationCellPopulation)

set(CMAKE_CXX_FLAGS "-std=c++11 -g3 -march=native -Wall -Werror -Wextra -pedantic -s")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/source)


file (
    GLOB
    source_files
    source/CellDynamics/*.cpp
    source/Domains/*.cpp
    source/Manager/*.cpp
    source/Models/*.cpp
    source/Random/*.cpp
)

add_executable (
    sims
    source/main.cpp
    ${source_files}
)

TARGET_LINK_LIBRARIES(
    sims
    m
)


file (
    GLOB
    test_files
)

add_executable (
    tests
    test/main.cpp
    ${test_files}
    ${source_files}
)


TARGET_LINK_LIBRARIES(
    tests
    m
    gtest
    pthread
    gmock
)
