#ifndef TESTPARTICLE_H
#define TESTPARTICLE_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Models/Particle.hpp"


TEST(Particle, CanBeCreated) {
    Particle *particle = new Particle ();
    EXPECT_TRUE(particle != NULL);
    delete particle;
}

#endif
