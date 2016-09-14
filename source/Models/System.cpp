#include <vector>
#include "Models/Cell.hpp"
#include "Models/Particle.hpp"
#include "Models/System.hpp"
#include "Random/MersenneTwister.hpp"

System::System(MersenneTwister *mersenne_twister) {
  this->particles = new std::vector<Particle *>();
  this->cells = new std::vector<Cell *>();
  this->mersenne_twister = mersenne_twister;
}

System::~System() {
  for (auto particle : *this->particles) {
    delete particle;
  }
  delete this->particles;

  for (auto cell : *this->cells) {
    delete cell;
  }
  delete this->cells;
}

Particle * System::pick_particle() {
  int index = int(this->mersenne_twister->unit() * this->particles->size());
  return this->particles->at(index);
}
