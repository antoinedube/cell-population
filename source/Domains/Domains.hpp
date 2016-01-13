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
    virtual void remove(Particle *particle);

    virtual std::vector<Particle *> vector_at(int i);
    virtual int position_to_domain_index(int x, int y);
    virtual std::vector<int> indices_of_neighbors(int i);
    virtual int total_size();

 private:
    std::vector<Particle *> *domain_matrix;
};

#endif
