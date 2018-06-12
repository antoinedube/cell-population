#ifndef TESTINTEGRATION_H
#define TESTINTEGRATION_H

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "integration/integration.hpp"
#include "test/domains/mock-domains.hpp"
#include "test/models/mock-parameters.hpp"
#include "test/models/mock-system.hpp"
#include "test/random/mock-mersenne-twister.hpp"

TEST(Integration, CanBeCreated) {
    MockDomains *mock_domains = new MockDomains();
    MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
    MockSystem *mock_system = new MockSystem(mock_mersenne_twister);
    MockParameters *mock_parameters = new MockParameters();

    Integration *integration = new Integration(mock_domains, mock_parameters, mock_system);
    EXPECT_TRUE ( integration != NULL );

    delete integration;
    delete mock_parameters;
    delete mock_system;
    delete mock_mersenne_twister;
    delete mock_domains;
}

#endif
