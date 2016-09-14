#ifndef TESTPARTICLE_H
#define TESTPARTICLE_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Models/Particle.hpp"
#include "test/Random/MockMersenneTwister.hpp"

TEST(Particle, CanBeCreated) {
  MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();

  Particle *particle = new Particle(0, 0, mock_mersenne_twister);
  EXPECT_TRUE(particle != NULL);

  delete particle;
  delete mock_mersenne_twister;
}

#endif
