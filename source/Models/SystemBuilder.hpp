#ifndef SYSTEMBUILDER_HPP
#define SYSTEMBUILDER_HPP

#include "Models/System.hpp"
#include "Random/MersenneTwister.hpp"


class SystemBuilder {
 public:
    SystemBuilder();
    virtual ~SystemBuilder();

    MersenneTwister *mersenne_twister;
    System *system;
};

#endif
