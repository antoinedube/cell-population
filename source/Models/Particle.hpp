#ifndef PARTICLE_HPP
#define PARTICLE_HPP


class Particle {
 public:
    Particle(int x, int y);
    virtual ~Particle();

    virtual void accept_trial();

    int id;

    int x;
    int y;

    int trial_x;
    int trial_y;
};

#endif
