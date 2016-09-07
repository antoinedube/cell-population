#include <algorithm>
#include <iostream>
#include <vector>

#include "Domains/Domains.hpp"
#include "Models/Particle.hpp"

// Change 100*100 for grid size, in Parameters

Domains::Domains() {
  this->domain_matrix = new std::vector<Particle *>[100*100];
  this->cell_size_x = 10;
  this->cell_size_y = 10;
  this->system_size_x = 100;
  this->system_size_y = 100;
}

Domains::~Domains() {
  delete[] this->domain_matrix;
}

std::vector<Particle *> Domains::vector_at(int i) {
  return this->domain_matrix[i];
}

int Domains::position_to_domain_index(int x, int y) {
  return x*100+y;
}

void Domains::add(Particle *particle) {
  int index = this->position_to_domain_index(particle->x, particle->y);
  std::cout << "Index when adding: " << index << std::endl;
  this->domain_matrix[index].push_back(particle);
}

void Domains::remove(Particle *particle) {
  // Must find in vectors of "get_neighboring_particles"
  int index = this->position_to_domain_index(particle->x, particle->y);
  this->domain_matrix[index].erase(std::remove(this->domain_matrix[index].begin(), this->domain_matrix[index].end(), particle), this->domain_matrix[index].end());
}

std::vector<Particle *> Domains::get_neighboring_particles(Particle *particle) {
  std::vector<Particle *> neighboring_particles;
  // Add particles of neighboring domains

  std::vector<int> index_neighbors = this->indices_of_neighboring_domains(particle->x, particle->y);
  for (auto index : index_neighbors) {
    std::cout << "Neighboring indices: " << index << std::endl;
    std::vector<Particle *> current = this->vector_at(index);
    for (auto item : current) {
      neighboring_particles.push_back(item);
    }
  }

  return neighboring_particles;
}

std::vector<int> Domains::indices_of_neighboring_domains(int x, int y) {
  std::vector<int> neighbors;

  // x and y are positions, not indices
  // Should be +/- gridcell size
  for (auto nx=x-1 ; nx<=x+1 ; nx++) {
    for (auto ny=y-1 ; ny<=y+1 ; ny++) {
      if (nx<0 || ny<0 || nx>99 || ny>99) {
        std::cout << "Domains::indices_of_neighboring_domains : invalid index\t" << nx << ", " << ny << std::endl;
      }
      else if (nx==-1 && ny==-1) {
        neighbors.push_back(this->position_to_domain_index(99,99));
      }
      else if (nx==-1 && ny==100) {
        neighbors.push_back(this->position_to_domain_index(99,0));
      }
      else if (nx==100 && ny==-1) {
        neighbors.push_back(this->position_to_domain_index(0,99));
      }
      else if (nx==100 && ny==100) {
        neighbors.push_back(this->position_to_domain_index(0,0));
      }
      else if (nx==-1) {
        neighbors.push_back(this->position_to_domain_index(99,ny));
      }
      else if (nx==100) {
        neighbors.push_back(this->position_to_domain_index(0,ny));
      }
      else if (ny==-1) {
        neighbors.push_back(this->position_to_domain_index(nx,99));
      }
      else if (ny==100) {
        neighbors.push_back(this->position_to_domain_index(nx,0));
      }
      else {
        neighbors.push_back(this->position_to_domain_index(nx,ny));
      }
    }
  }

  return neighbors;
}

int Domains::total_size() {
  int size = 0;

  for (auto i=0 ; i<100*100 ; i++) {
    size += this->domain_matrix[i].size();
  }

  return size;
}
