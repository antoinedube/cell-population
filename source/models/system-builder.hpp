#ifndef SYSTEMBUILDER_HPP
#define SYSTEMBUILDER_HPP

#include "domains/domains.hpp"
#include "models/parameters.hpp"
#include "models/system.hpp"
#include "random/mersenne-twister.hpp"

class SystemBuilder {
public:
  SystemBuilder(Domains *domains, MersenneTwister *mersenne_twister, Parameters *parameters);
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
