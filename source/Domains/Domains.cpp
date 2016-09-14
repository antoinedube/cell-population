#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "Domains/Domains.hpp"
#include "Models/Particle.hpp"

Domains::Domains() {
  this->cell_size_x = 10;
  this->cell_size_y = 10;
  this->num_cell_x = 100;
  this->num_cell_y = 100;
  this->system_size_x = this->cell_size_x * this->num_cell_x;
  this->system_size_y = this->cell_size_y * this->num_cell_y;

  // vector of vector should be better
  this->domain_matrix = new std::vector<Particle *>[this->num_cell_x * this->num_cell_y]();
}

Domains::~Domains() {
  delete[] this->domain_matrix;
}

std::vector<Particle *> Domains::vector_at(int i) {
  return this->domain_matrix[i];
}

int Domains::position_to_domain_index(int x, int y) {
  int index_x = int(x/this->cell_size_x);
  int index_y = int(y/this->cell_size_y);

  return index_x*(this->num_cell_y-1)+index_y;
}

void Domains::add(Particle *particle) {
  int index = this->position_to_domain_index(particle->x, particle->y);
  this->domain_matrix[index].push_back(particle);
}

void Domains::remove(Particle *particle) {
  // Must find in vectors of "get_neighboring_particles"
  int index = this->position_to_domain_index(particle->x, particle->y);
  this->domain_matrix[index].erase(std::remove(this->domain_matrix[index].begin(), this->domain_matrix[index].end(), particle), this->domain_matrix[index].end());
}

std::vector<Particle *> Domains::get_neighboring_particles(Particle *particle) {
  std::vector<Particle *> neighboring_particles;
  std::vector<int> index_neighbors = this->indices_of_neighboring_domains(particle->x, particle->y); // Trial position or not?
  for (auto index : index_neighbors) {
    std::vector<Particle *> current = this->vector_at(index);
    for (auto item : current) {
      neighboring_particles.push_back(item);
    }
  }

  return neighboring_particles;
}

std::vector<int> Domains::indices_of_neighboring_domains(int x, int y) {
  std::vector<int> neighbors;

  for (int i=-1; i<2; i++) {
    for (int j=-1; j<2; j++) {
      int nx = x + i*this->cell_size_x;
      int ny = y + j*this->cell_size_y;

      while (nx<0) nx += this->system_size_x;
      while (ny<0) ny += this->system_size_y;
      while (nx>=this->system_size_x) nx -= this->system_size_x;
      while (ny>=this->system_size_y) ny -= this->system_size_y;

      if (nx<0 || ny<0 || nx>this->system_size_x || ny>this->system_size_y) {
        throw std::invalid_argument("Received invalid positions");
      }
      neighbors.push_back(this->position_to_domain_index(nx, ny));
    }
  }

  return neighbors;
}

int Domains::total_size() {
  int size = 0;

  for (int i=0; i<int(100*100); i++) {
    size += this->domain_matrix[i].size();
  }

  return size;
}

bool Domains::is_trial_site_available(Particle * /*particle*/) {
  return false;
}
