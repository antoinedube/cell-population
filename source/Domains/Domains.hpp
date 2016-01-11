#ifndef DOMAINS_HPP
#define DOMAINS_HPP

#include <vector>
#include <Models/Particle.hpp>


class Domains {
 public:
    Domains();
    virtual ~Domains();

    virtual std::vector<Particle *> get_neighboring_particles(Particle *particle);
    virtual void add(Particle *particle);
    virtual void update(Particle *particle);
    virtual void remove(Particle *particle);

 private:
    std::vector< std::vector< std::vector<Particle *> > > *domain_matrix;
};

#endif
