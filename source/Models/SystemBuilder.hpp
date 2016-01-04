#ifndef SYSTEMBUILDER_HPP
#define SYSTEMBUILDER_HPP

#include "Domains/Domains.hpp"
#include "Models/Parameters.hpp"
#include "Models/System.hpp"
#include "Random/MersenneTwister.hpp"


class SystemBuilder {
 public:
    SystemBuilder(Parameters *parameters, Domains *domains, MersenneTwister *mersenne_twister);
    virtual ~SystemBuilder();
    virtual SystemBuilder* add_cell();
    virtual System* build();

 private:
    Domains *domains;
    MersenneTwister *mersenne_twister;
    Parameters *parameters;
    System *system;
};

#endif
