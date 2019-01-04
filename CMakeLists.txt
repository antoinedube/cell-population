cmake_minimum_required (VERSION 2.8)

project (SimulationCellPopulation)

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -g3 -march=native -Wall -Werror -Wextra -pedantic -s")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -Ofast -march=native -Wall -Werror -Wextra -pedantic -s")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/source)

ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


file (
  GLOB
  source_files
  source/**/*.cpp
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
  gtest_main
  pthread
  gmock
)
