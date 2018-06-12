#include "models/parameters.hpp"

Parameters::Parameters(int n_cycles, int n_steps, int system_size_x, int system_size_y) {
    this->system_size_x = system_size_x;
    this->system_size_y = system_size_y;

    this->n_cycles = n_cycles;
    this->n_steps = n_steps;
}

Parameters::~Parameters() {
}
