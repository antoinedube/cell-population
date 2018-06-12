#ifndef MOCKMERSENNETWISTER_H
#define MOCKMERSENNETWISTER_H

#include "gmock/gmock.h"

#include "random/mersenne-twister.hpp"


class MockMersenneTwister : public MersenneTwister {
public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
