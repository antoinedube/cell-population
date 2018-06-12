#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "random/mersenne-twister.hpp"

class Cell;

class Particle {
public:
    Particle(int x, int y, MersenneTwister *mersenne_twister);
    virtual ~Particle();

    virtual void accept_trial();
    virtual void reject_trial();
    virtual void take_random_step();
    virtual double distance_to(Particle *particle);
    virtual void print();

    int id;
    int x;
    int y;
    int trial_x;
    int trial_y;

    Cell *parent_cell;
    MersenneTwister *mersenne_twister;
};

#endif // PARTICLE_HPP
