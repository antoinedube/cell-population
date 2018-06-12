#include <iostream>

#include "domains/domains.hpp"
#include "models/cell.hpp"
#include "models/parameters.hpp"
#include "models/particle.hpp"
#include "models/system.hpp"
#include "models/system-builder.hpp"

SystemBuilder::SystemBuilder(Domains *domains, MersenneTwister *mersenne_twister, Parameters *parameters) {
    this->domains = domains;
    this->mersenne_twister = mersenne_twister;
    this->parameters = parameters;
    this->system = new System(mersenne_twister);
}

SystemBuilder::~SystemBuilder() {
}

SystemBuilder* SystemBuilder::add_cell() {
    int x = int(0.5*this->parameters->system_size_x);
    int y = int(0.5*this->parameters->system_size_y);

    Cell *target_cell = new Cell();
    Particle *target_particle;

    for (int i=0 ; i<10 ; i++) {
        target_particle = new Particle(x, y, mersenne_twister);
        target_particle->accept_trial();
        domains->add(target_particle);

        target_particle->parent_cell = target_cell;

        target_cell->particles->push_back(target_particle);
        system->particles->push_back(target_particle);

        x++;
    }

    x--;
    y++;

    for (int i=0 ; i<10 ; i++) {
        target_particle = new Particle(x, y, mersenne_twister);
        target_particle->accept_trial();
        domains->add(target_particle);

        target_particle->parent_cell = target_cell;

        target_cell->particles->push_back(target_particle);
        system->particles->push_back(target_particle);

        x--;
    }

    system->cells->push_back(target_cell);

    return this;
}

System* SystemBuilder::build() {
    return this->system;
}
