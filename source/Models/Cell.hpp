#ifndef CELL_HPP
#define CELL_HPP

#include <vector>

#include "Models/Particle.hpp"


class Cell {
 public:
    Cell();
    virtual ~Cell();

    virtual int size();

    std::vector<Particle *> *particles;
};

#endif
