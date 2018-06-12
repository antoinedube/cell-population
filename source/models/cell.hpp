#ifndef CELL_HPP
#define CELL_HPP

#include <string>
#include <vector>

#include "models/particle.hpp"


class Cell {
public:
    Cell();
    virtual ~Cell();
    virtual int size();
    virtual std::string print();

    std::vector<Particle *> *particles;
};

#endif
