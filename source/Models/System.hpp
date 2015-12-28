#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>

#include "Models/Cell.hpp"
#include "Models/Particle.hpp"


class System {
 public:
    System();
    virtual ~System();

    std::vector<Particle *> *particles;
    std::vector<Cell *> *cells;
};

#endif
