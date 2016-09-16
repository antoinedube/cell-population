#include "Integration/Integration.hpp"
#include "Models/Parameters.hpp"
#include "Models/System.hpp"
#include "Random/MersenneTwister.hpp"

Integration::Integration(Parameters *parameters, System *system) {
  this->parameters = parameters;
  this->system = system;
}

Integration::~Integration() {
}

void Integration::run() {
  for (int cycle=0; cycle<this->parameters->n_cycles; cycle++) {
    for (int step=0; step<this->parameters->n_steps; step++) {
      this->system->pick_particle();

      // Take random step

      // Check if site is available

      // If the particle is in a cell, check neighbors in chain

      // Metropolis-Hastings check using cell dynamics
    }
  }
}
