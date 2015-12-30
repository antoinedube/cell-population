#ifndef TESTSYSTEM_H
#define TESTSYSTEM_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Models/System.hpp"


TEST(System, CanBeCreated) {
    System *system = new System ();
    EXPECT_TRUE(system != NULL);
    delete system;
}

#endif
