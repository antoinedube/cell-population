#ifndef TESTMANAGER_H
#define TESTMANAGER_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Manager/Manager.hpp"

TEST ( Manager, CanBeCreated ) {
    Manager *manager = new Manager ();
    EXPECT_TRUE ( manager != NULL );
    delete manager;
}

#endif // TESTMANAGER_H
