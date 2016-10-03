#include <iostream>
#include "Domains/Domains.hpp"
#include "Integration/Integration.hpp"
#include "Models/Parameters.hpp"
#include "Models/System.hpp"
#include "Random/MersenneTwister.hpp"

Integration::Integration(Domains *domains, Parameters *parameters, System *system) {
  this->domains = domains;
  this->parameters = parameters;
  this->system = system;
}

Integration::~Integration() {
}

void Integration::run() {
  Particle *current_particle;
  for (int cycle=0; cycle<this->parameters->n_cycles; cycle++) {
    for (int step=0; step<this->parameters->n_steps; step++) {
      current_particle = this->system->pick_particle();

      // Take random step
      current_particle->take_random_step();

      // Check if site is available

      // If the particle is in a cell, check neighbors in chain

      // Metropolis-Hastings check using cell dynamics

    }
    std::cout << "Cycle " << cycle <<  " of " << this->parameters->n_cycles << std::endl;
  }
}
