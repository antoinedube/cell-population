#ifndef TESTSYSTEM_H
#define TESTSYSTEM_H

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Models/System.hpp"
#include "test/Random/MockMersenneTwister.hpp"

TEST(System, CanBeCreated) {
  MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
  System *system = new System (mock_mersenne_twister);

  EXPECT_TRUE(system != NULL);

  delete system;
  delete mock_mersenne_twister;
}

#endif
