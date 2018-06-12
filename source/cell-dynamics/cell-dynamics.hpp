#ifndef CELLDYNAMICS_H
#define CELLDYNAMICS_H

#include "models/particle.hpp"

class CellDynamics {
public:
    CellDynamics();
    virtual ~CellDynamics();

    virtual void accept_trial(Particle *particle) = 0;
};

#endif /* CELLDYNAMICS_H */
