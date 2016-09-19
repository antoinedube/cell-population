#ifndef TESTINTEGRATION_H
#define TESTINTEGRATION_H

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Integration/Integration.hpp"
#include "test/Models/MockParameters.hpp"
#include "test/Models/MockSystem.hpp"
#include "test/Random/MockMersenneTwister.hpp"

TEST ( Integration, CanBeCreated ) {
  MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
  MockSystem *mock_system = new MockSystem(mock_mersenne_twister);
  MockParameters *mock_parameters = new MockParameters();

  Integration *integration = new Integration(mock_parameters, mock_system);
  EXPECT_TRUE ( integration != NULL );

  delete integration;
  delete mock_parameters;
  delete mock_system;
  delete mock_mersenne_twister;
}

#endif
