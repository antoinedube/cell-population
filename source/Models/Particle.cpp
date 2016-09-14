#include "Models/Particle.hpp"
#include "Random/MersenneTwister.hpp"

Particle::Particle(int x, int y, MersenneTwister *mersenne_twister) {
  this->id = 0;
  this->trial_x = x;
  this->trial_y = y;
  this->parent_cell = NULL;
  this->mersenne_twister = mersenne_twister;
}

Particle::~Particle() {
}

void Particle::accept_trial() {
  this->x = this->trial_x;
  this->y = this->trial_y;
}

void Particle::take_random_step() {
  double r = mersenne_twister->unit();
  if (r<0.25) {
    this->trial_x = this->x - 1;
  }
  else if (r<0.5) {
    this->trial_x = this->x + 1;
  }
  else if (r<0.75) {
    this->trial_y = this->y - 1;
  }
  else {
    this->trial_y = this->y + 1;
  }
}
