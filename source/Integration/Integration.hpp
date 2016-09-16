#ifndef INTEGRATION_HPP
#define INTEGRATION_HPP

#include "Models/Parameters.hpp"
#include "Models/System.hpp"

class Integration {
public:
  Integration(Parameters *parameters, System *system);
  virtual ~Integration();

  virtual void run();
private:
  Parameters *parameters;
  System *system;
};

#endif
