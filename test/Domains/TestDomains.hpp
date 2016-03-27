#ifndef TESTDOMAINS_H
#define TESTDOMAINS_H

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Domains/Domains.hpp"
#include "Models/Particle.hpp"


TEST(Domains, CanBeCreated) {
    Domains *domains = new Domains();
    EXPECT_TRUE(domains != NULL);
    delete domains;
}

TEST(Domains, CanAddParticle) {
    Domains *domains = new Domains();
    Particle *particle = new Particle(15,15);
    domains->add(particle);

    EXPECT_TRUE(domains->total_size() == 1);

    delete particle;
    delete domains;
}

TEST(Domains, CanRemoveParticle) {
    Domains *domains = new Domains();
    Particle *particle = new Particle(15,15);
    domains->add(particle);

    EXPECT_TRUE(domains->total_size() == 1);

    domains->remove(particle);

    EXPECT_TRUE(domains->total_size() == 0);

    delete particle;
    delete domains;
}

TEST(Domains, CanRecoverIndicesOfNeighboringDomains) {
    Domains *domains = new Domains();
    int x = 4;
    int y = 5;
    std::vector<int> neighbors = domains->indices_of_neighboring_domains(x,y);

    EXPECT_TRUE(neighbors.at(0) == (x-1)*100+(y-1));
    EXPECT_TRUE(neighbors.at(4) == x*100+y);

    delete domains;
}

#endif
