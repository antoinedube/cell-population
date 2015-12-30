#include <string>
#include <sstream>
#include <vector>

#include "Models/Cell.hpp"
#include "Models/Particle.hpp"


Cell::Cell() {
    this->particles = new std::vector<Particle *>();
}

Cell::~Cell() {
    delete this->particles;
}

int Cell::size() {
    return this->particles->size();
}

std::string Cell::print() {
    std::ostringstream output;
    for (auto particle : *this->particles) {
        output << particle->x << ", " << particle->y << std::endl;
    }

    return output.str();
}
