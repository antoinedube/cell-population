#ifndef MOCKSYSTEM_H
#define MOCKSYSTEM_H

#include "gmock/gmock.h"
#include "Models/System.hpp"


class MockSystem : public System {
    public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
