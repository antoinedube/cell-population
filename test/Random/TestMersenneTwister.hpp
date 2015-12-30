#ifndef TESTMERSENNETWISTER_H
#define TESTMERSENNETWISTER_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Random/MersenneTwister.hpp"


TEST(MersenneTwister, CanBeCreated) {
    MersenneTwister *mersenne_twister = new MersenneTwister ();
    EXPECT_TRUE(mersenne_twister != NULL);
    delete mersenne_twister;
}


TEST(MersenneTwister, CanGenerateRandomNumberWithNormalDistribution) {
    MersenneTwister *mersenne_twister = new MersenneTwister ();

    double value = 0.0;
    double sum = 0.0;
    double mean = 0.0;
    double count = 0.0;
    for (int i=0 ; i<10000000 ; i++) {
        value = mersenne_twister->normal();
        sum += value;
        count += 1.0;
    }

    mean = sum/count;
    EXPECT_TRUE(fabs(mean)<1.0e-3);

    delete mersenne_twister;
}

TEST(MersenneTwister, CanGenerateRandomNumberWithUniformDistribution) {
    MersenneTwister *mersenne_twister = new MersenneTwister ();

    double value = 0.0;
    double sum = 0.0;
    double mean = 0.0;
    double count = 0.0;
    for (int i=0 ; i<10000000 ; i++) {
        value = mersenne_twister->unit();
        sum += value;
        count += 1.0;
    }

    mean = sum/count;
    EXPECT_TRUE(fabs(0.5 - mean)<1.0e-3);

    delete mersenne_twister;
}

#endif
