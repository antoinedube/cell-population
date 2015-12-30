#include <iostream>

#include "Models/Cell.hpp"
#include "Models/Parameters.hpp"
#include "Models/Particle.hpp"
#include "Models/System.hpp"
#include "Models/SystemBuilder.hpp"


SystemBuilder::SystemBuilder(Parameters *parameters) {
    this->parameters = parameters;
    this->system = new System();
}

SystemBuilder::~SystemBuilder() {
}

SystemBuilder* SystemBuilder::add_cell() {
    int x = int(0.5*this->parameters->system_size_x);
    int y = int(0.5*this->parameters->system_size_y);

    Cell *target_cell = new Cell();
    Particle *target_particle;

    for (int i=0 ; i<10 ; i++) {
        target_particle = new Particle();
        target_particle->x = x;
        target_particle->y = y;

        target_cell->particles->push_back(target_particle);
        system->particles->push_back(target_particle);

        x++;
    }

    x--;
    y++;

    for (int i=0 ; i<10 ; i++) {
        target_particle = new Particle();
        target_particle->x = x;
        target_particle->y = y;

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
