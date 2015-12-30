#ifndef MOCKSYSTEMBUILDER_H
#define MOCKSYSTEMBUILDER_H

#include "gmock/gmock.h"
#include "Models/SystemBuilder.hpp"


class MockSystemBuilder : public SystemBuilder {
    public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
