#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>

#include "models/cell.hpp"
#include "models/particle.hpp"
#include "random/mersenne-twister.hpp"

class System {
public:
    System(MersenneTwister *mersenne_twister);
    virtual ~System();

    virtual Particle * pick_particle();

    std::vector<Particle *> *particles;
    std::vector<Cell *> *cells;
    MersenneTwister *mersenne_twister;
};

#endif
