#include <cmath>
#include <iostream>

#include "models/particle.hpp"
#include "random/mersenne-twister.hpp"

Particle::Particle(int x, int y, MersenneTwister *mersenne_twister) {
    this->id = 0;
    this->x = x;
    this->y = y;
    this->trial_x = x;
    this->trial_y = y;
    this->parent_cell = NULL;
    this->left_neighbor = NULL;
    this->right_neighbor = NULL;
    this->mersenne_twister = mersenne_twister;
}

Particle::~Particle() {
}

void Particle::accept_trial() {
    this->x = this->trial_x;
    this->y = this->trial_y;
}

void Particle::reject_trial() {
    this->trial_x = this->x;
    this->trial_y = this->y;
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

double Particle::distance_to(Particle *particle) {
    double distance = 0.0;
    double delta_x = particle->x - this->x;
    double delta_y = particle->y - this->y;
    distance = delta_x*delta_x + delta_y*delta_y;
    return sqrt(distance);
}

void Particle::print() {
        std::cout << id << " -- "
                            << x << ", " << y << " -- "
                            << trial_x << ", " << trial_y << std::endl;
}
