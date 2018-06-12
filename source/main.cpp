#include <iostream>

#include "domains/domains.hpp"
#include "integration/integration.hpp"
#include "models/parameters.hpp"
#include "models/system-builder.hpp"
#include "random/mersenne-twister.hpp"

int main() {
    Domains *domains = new Domains();
    Parameters *parameters = new Parameters();
    MersenneTwister *mersenne_twister = new MersenneTwister();
    SystemBuilder *system_builder = new SystemBuilder(domains, mersenne_twister, parameters);
    System *system = system_builder->add_cell()->build();
    delete system_builder;

    Integration *integration = new Integration(domains, parameters, system);
    integration->run();

    delete integration;
    delete domains;
    delete mersenne_twister;
    delete parameters;
    delete system;

    return 0;
}
