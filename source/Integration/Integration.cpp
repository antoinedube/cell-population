#include "Integration/Integration.hpp"
#include "Models/Parameters.hpp"

Integration::Integration(Parameters *parameters) {
  this->parameters = parameters;
}

Integration::~Integration() {
}

void Integration::run() {
  for (int cycle=0; cycle<this->parameters->n_cycles; cycle++) {
    for (int step=0; step<this->parameters->n_steps; step++) {

    }
  }
}
