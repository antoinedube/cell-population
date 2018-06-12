#ifndef TESTCELL_H
#define TESTCELL_H

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "models/cell.hpp"


TEST(Cell, CanBeCreated) {
    Cell *cell = new Cell ();
    EXPECT_TRUE(cell != NULL);
    delete cell;
}

#endif
