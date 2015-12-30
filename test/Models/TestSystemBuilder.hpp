#ifndef TESTSYSTEMBUILDER_H
#define TESTSYSTEMBUILDER_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "test/Models/MockParameters.hpp"
#include "Models/SystemBuilder.hpp"


TEST(SystemBuilder, CanBeCreated) {
    MockParameters *mock_parameters = new MockParameters();
    SystemBuilder *system_builder = new SystemBuilder(mock_parameters);
    System *system = system_builder->build();

    EXPECT_TRUE(system_builder != NULL);

    delete system_builder;
    delete system;
    delete mock_parameters;
}

TEST(SystemBuilder, CanAddCellToSystem) {
    MockParameters *mock_parameters = new MockParameters();
    SystemBuilder *system_builder = new SystemBuilder(mock_parameters);
    System *system;

    system = system_builder->add_cell()->build();

    EXPECT_TRUE(system->cells->size() > 0);

    delete system_builder;
    delete system;
    delete mock_parameters;
}

#endif
