#ifndef TESTDOMAINS_H
#define TESTDOMAINS_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Domains/Domains.hpp"


TEST(Domains, CanBeCreated) {
    Domains *domains = new Domains();
    EXPECT_TRUE(domains != NULL);
    delete domains;
}

#endif
