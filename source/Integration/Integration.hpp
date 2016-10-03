#ifndef INTEGRATION_HPP
#define INTEGRATION_HPP

#include "Domains/Domains.hpp"
#include "Models/Parameters.hpp"
#include "Models/System.hpp"

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
