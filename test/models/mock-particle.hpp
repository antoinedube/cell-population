#ifndef MOCKPARTICLE_H
#define MOCKPARTICLE_H

#include "gmock/gmock.h"

#include "models/particle.hpp"


class MockParticle : public Particle {
    public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
