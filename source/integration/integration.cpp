#include <iostream>

#include "domains/domains.hpp"
#include "integration/integration.hpp"
#include "models/parameters.hpp"
#include "models/system.hpp"
#include "random/mersenne-twister.hpp"

Integration::Integration(Domains *domains, Parameters *parameters, System *system) {
    this->domains = domains;
    this->parameters = parameters;
    this->system = system;
}

Integration::~Integration() {}

void Integration::run() {
    Particle *current_particle;
    for (int cycle=0; cycle<this->parameters->n_cycles; cycle++) {
        // Count successful steps instead of total
        for (int step=0; step<this->parameters->n_steps; step++) {
            current_particle = this->system->pick_particle();

            // Take random step
            current_particle->take_random_step();

            // Check if site is available
            if (!this->domains->is_trial_site_available(current_particle)) {
                continue;
            }

            // If the particle is in a cell (not domain cell, but biological cell), check neighbors in chain (chain as in chain of particle consisting of (biological) cell wall)

            // Metropolis-Hastings check using cell dynamics

        }
        std::cout << "Cycle " << cycle << " of " << this->parameters->n_cycles << std::endl;
    }
}
