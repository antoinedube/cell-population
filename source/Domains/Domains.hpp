#ifndef DOMAINS_HPP
#define DOMAINS_HPP

#include <vector>
#include "Models/Particle.hpp"

class Domains {
public:
  Domains();
  virtual ~Domains();

  virtual std::vector<Particle *> get_neighboring_particles(Particle *particle);

  virtual void add(Particle *particle);
  virtual void remove(Particle *particle);

  virtual std::vector<int> indices_of_neighboring_domains(int x, int y);
  virtual bool is_trial_site_available(Particle *particle);
  virtual int position_to_domain_index(int x, int y);
  virtual int total_size();
  virtual std::vector<Particle *> vector_at(int i);

private:
  std::vector<Particle *> *domain_matrix;
  int cell_size_x;
  int cell_size_y;
  int num_cell_x;
  int num_cell_y;
  int system_size_x;
  int system_size_y;
};

#endif
