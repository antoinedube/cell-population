#ifndef TESTSYSTEMBUILDER_H
#define TESTSYSTEMBUILDER_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Models/SystemBuilder.hpp"

#include "test/Domains/MockDomains.hpp"
#include "test/Models/MockParameters.hpp"
#include "test/Random/MockMersenneTwister.hpp"

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
  System *system;

  system = system_builder->add_cell()->build();

  EXPECT_TRUE(system->cells->size() > 0);

  delete system_builder;
  delete system;
  delete mock_domains;
  delete mock_mersenne_twister;
  delete mock_parameters;
}

#endif
