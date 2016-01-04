#include "Models/Particle.hpp"


Particle::Particle(int x, int y) {
    this->trial_x = x;
    this->trial_y = y;
}

Particle::~Particle() {
}

void Particle::accept_trial() {
    this->x = this->trial_x;
    this->y = this->trial_y;
}
