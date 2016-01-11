#ifndef SYSTEMBUILDER_HPP
#define SYSTEMBUILDER_HPP

#include "Models/Parameters.hpp"
#include "Models/System.hpp"
#include "Random/MersenneTwister.hpp"


class SystemBuilder {
 public:
    SystemBuilder(Parameters *parameters, MersenneTwister *mersenne_twister);
    virtual ~SystemBuilder();
    virtual SystemBuilder* add_cell();
    virtual System* build();

 private:
    MersenneTwister *mersenne_twister;
    Parameters *parameters;
    System *system;
};

#endif
