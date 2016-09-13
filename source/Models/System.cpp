#include <vector>
#include "Models/Cell.hpp"
#include "Models/Particle.hpp"
#include "Models/System.hpp"

System::System() {
  this->particles = new std::vector<Particle *>();
  this->cells = new std::vector<Cell *>();
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
