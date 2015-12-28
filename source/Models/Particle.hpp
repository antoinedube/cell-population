#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle {
 public:
    Particle();
    virtual ~Particle();

    int x;
    int y;

    int trial_x;
    int trial_y;
};

#endif
