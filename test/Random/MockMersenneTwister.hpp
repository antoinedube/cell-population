#ifndef MOCKMERSENNETWISTER_H
#define MOCKMERSENNETWISTER_H

#include "gmock/gmock.h"
#include "Random/MersenneTwister.hpp"


class MockMersenneTwister : public MersenneTwister {
    public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
