#ifndef MOCKSYSTEMBUILDER_H
#define MOCKSYSTEMBUILDER_H

#include "gmock/gmock.h"

#include "models/system-builder.hpp"


class MockSystemBuilder : public SystemBuilder {
public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
