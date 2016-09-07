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

TEST(Domains, CanReturnParticlesInNeighboringDomains) {
  Domains *domains = new Domains();

  Particle *reference_particle = new Particle(15, 15);
  reference_particle->accept_trial();

  Particle *compared_particle = new Particle(22, 15);
  compared_particle->accept_trial();

  domains->add(compared_particle);

  std::vector<Particle *> particlesInNeighborhood = domains->get_neighboring_particles(reference_particle);
  std::cout << "Size: " << particlesInNeighborhood.size() << std::endl;
  for (auto item : particlesInNeighborhood) {
    std::cout << "item: " << item << std::endl;
  }

  EXPECT_TRUE(1==0);

  delete reference_particle;
  delete compared_particle;
  delete domains;
}

#endif
