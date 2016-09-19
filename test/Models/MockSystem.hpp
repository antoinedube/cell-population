#ifndef MOCKSYSTEM_H
#define MOCKSYSTEM_H

#include "gmock/gmock.h"
#include "Models/System.hpp"
#include "test/Random/MockMersenneTwister.hpp"

class MockSystem : public System {
public:
  MockSystem(MockMersenneTwister *mock_mersenne_twister);
};

MockSystem::MockSystem(MockMersenneTwister * mock_mersenne_twister) : System(mock_mersenne_twister) {}

#endif
