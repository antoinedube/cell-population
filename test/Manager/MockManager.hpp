#ifndef MOCKMANAGER_H
#define MOCKMANAGER_H

#include "gmock/gmock.h"
#include "Manager.hpp"

class MockManager : public Manager {
    public:
    MOCK_METHOD0 ( execute, void() );
};

#endif // MOCKMANAGER_H
