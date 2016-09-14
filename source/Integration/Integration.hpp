#ifndef INTEGRATION_HPP
#define INTEGRATION_HPP

#include "Models/Parameters.hpp"

class Integration {
public:
  Integration(Parameters *parameters);
  virtual ~Integration();

  virtual void run();
private:
  Parameters *parameters;
};

#endif
