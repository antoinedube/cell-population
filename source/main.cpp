#include <iostream>
#include "Domains/Domains.hpp"
#include "Integration/Integration.hpp"
#include "Models/Parameters.hpp"
#include "Models/SystemBuilder.hpp"
#include "Random/MersenneTwister.hpp"

int main() {
  Domains *domains = new Domains();
  Parameters *parameters = new Parameters();
  MersenneTwister *mersenne_twister = new MersenneTwister();
  SystemBuilder *system_builder = new SystemBuilder(domains, mersenne_twister, parameters);
  System *system = system_builder->add_cell()->build();
  delete system_builder;

  Integration *integration = new Integration(parameters, system);
  integration->run();

  delete integration;
  delete domains;
  delete mersenne_twister;
  delete parameters;
  delete system;
  return 0;
}
