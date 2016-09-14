#ifndef TESTINTEGRATION_H
#define TESTINTEGRATION_H

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Integration/Integration.hpp"
#include "test/Models/MockParameters.hpp"
#include "test/Random/MockMersenneTwister.hpp"

TEST ( Integration, CanBeCreated ) {
  MockParameters *mock_parameters = new MockParameters();

  Integration *integration = new Integration(mock_parameters);
  EXPECT_TRUE ( integration != NULL );

  delete integration;
  delete mock_parameters;
}

#endif
