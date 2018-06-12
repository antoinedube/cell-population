#ifndef INTEGRATION_HPP
#define INTEGRATION_HPP

#include "domains/domains.hpp"
#include "models/parameters.hpp"
#include "models/system.hpp"

class Integration {
public:
  Integration(Domains *domains, Parameters *parameters, System *system);
  virtual ~Integration();

  virtual void run();
private:
  Domains *domains;
  Parameters *parameters;
  System *system;
};

#endif
