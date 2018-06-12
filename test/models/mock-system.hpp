#ifndef MOCKSYSTEM_H
#define MOCKSYSTEM_H

#include "gmock/gmock.h"

#include "models/system.hpp"
#include "test/random/mock-mersenne-twister.hpp"

class MockSystem : public System {
public:
  MockSystem(MockMersenneTwister *mock_mersenne_twister);
};

MockSystem::MockSystem(MockMersenneTwister * mock_mersenne_twister) : System(mock_mersenne_twister) {}

#endif
