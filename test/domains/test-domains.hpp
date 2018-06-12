#ifndef TESTDOMAINS_H
#define TESTDOMAINS_H

#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "domains/domains.hpp"
#include "models/particle.hpp"
#include "test/random/mock-mersenne-twister.hpp"

TEST(Domains, CanBeCreated) {
  Domains *domains = new Domains();
  EXPECT_TRUE(domains != NULL);
  delete domains;
}

TEST(Domains, CanAddParticle) {
  Domains *domains = new Domains();
  MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
  Particle *particle = new Particle(15, 15, mock_mersenne_twister);
  domains->add(particle);

  EXPECT_TRUE(domains->total_size() == 1);

  delete particle;
  delete mock_mersenne_twister;
  delete domains;
}

TEST(Domains, CanRemoveParticle) {
  MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
  Particle *particle = new Particle(15, 15, mock_mersenne_twister);
  Domains *domains = new Domains();
  domains->add(particle);

  EXPECT_TRUE(domains->total_size() == 1);

  domains->remove(particle);

  EXPECT_TRUE(domains->total_size() == 0);

  delete domains;
  delete particle;
  delete mock_mersenne_twister;
}

TEST(Domains, CanRecoverIndicesOfNeighboringDomains) {
  Domains *domains = new Domains();
  int x = 4;
  int y = 5;
  std::vector<int> neighbors = domains->indices_of_neighboring_domains(x, y);

  EXPECT_EQ(9, neighbors.size());

  delete domains;
}

TEST(Domains, CanReturnParticlesInNeighboringDomains) {
  Domains *domains = new Domains();

  MockMersenneTwister *mock_mersenne_twister = new MockMersenneTwister();
  Particle *reference_particle = new Particle(15, 15, mock_mersenne_twister);
  reference_particle->accept_trial();

  Particle *compared_particle = new Particle(22, 15, mock_mersenne_twister);
  compared_particle->accept_trial();

  domains->add(compared_particle);

  std::vector<Particle *> particlesInNeighborhood = domains->get_neighboring_particles(reference_particle);
  for (auto item : particlesInNeighborhood) {
    EXPECT_EQ(compared_particle->x, item->x);
    EXPECT_EQ(compared_particle->y, item->y);
  }

  delete reference_particle;
  delete compared_particle;
  delete mock_mersenne_twister;
  delete domains;
}

#endif
