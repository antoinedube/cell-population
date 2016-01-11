#ifndef MOCKDOMAINS_H
#define MOCKDOMAINS_H

#include "gmock/gmock.h"
#include "Domains/Domains.hpp"


class MockDomains : public Domains {
    public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
