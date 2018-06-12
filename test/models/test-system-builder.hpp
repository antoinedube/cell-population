#ifndef TESTSYSTEMBUILDER_H
#define TESTSYSTEMBUILDER_H

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "models/system-builder.hpp"
#include "test/domains/mock-domains.hpp"
#include "test/models/mock-parameters.hpp"
#include "test/random/mock-mersenne-twister.hpp"

using ::testing::_;

TEST(SystemBuilder, CanBeCreated) {
    MockDomains *mock_domains = new MockDomains();
    MockParameters *mock_parameters = new MockParameters();
    MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
    SystemBuilder *system_builder = new SystemBuilder(mock_domains, mock_mersenne_twister, mock_parameters);
    System *system = system_builder->build();

    EXPECT_TRUE(system_builder != NULL);

    delete system_builder;
    delete system;
    delete mock_domains;
    delete mock_mersenne_twister;
    delete mock_parameters;
}

TEST(SystemBuilder, CanAddCellToSystem) {
    MockDomains *mock_domains = new MockDomains();
    MockParameters *mock_parameters = new MockParameters();
    MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
    SystemBuilder *system_builder = new SystemBuilder(mock_domains, mock_mersenne_twister, mock_parameters);

    EXPECT_CALL(*mock_domains, add(_)).Times(20);
    System *system = system_builder->add_cell()->build();
    EXPECT_TRUE(system->cells->size() > 0);

    delete system_builder;
    delete system;
    delete mock_domains;
    delete mock_mersenne_twister;
    delete mock_parameters;
}

#endif
