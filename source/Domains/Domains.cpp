#include <algorithm>
#include <iostream>
#include <vector>

#include "Domains/Domains.hpp"
#include "Models/Particle.hpp"

// Change 100*100 for grid size, in Parameters

Domains::Domains() {
    this->domain_matrix = new std::vector<Particle *>[100*100];
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
    this->domain_matrix[index].push_back(particle);
}

void Domains::remove(Particle *particle) {
    // Must check with vector of "get_neighboring_particles"
    int index = this->position_to_domain_index(particle->x, particle->y);
    this->domain_matrix[index].erase(std::remove(this->domain_matrix[index].begin(), this->domain_matrix[index].end(), particle), this->domain_matrix[index].end());
}

std::vector<Particle *> Domains::get_neighboring_particles(Particle *particle) {
    std::cout << "Get neighboring particles" << std::endl;
    // https://stackoverflow.com/questions/18147400/best-way-to-append-vector-to-vector

    std::vector<Particle *> neighboring_particles;
    neighboring_particles.push_back(particle);

    return neighboring_particles;
}

std::vector<int> Domains::indices_of_neighbors(int x, int y) {
    std::vector<int> neighbors;

    if (x==0) {
        neighbors.push_back(this->position_to_domain_index(100,y));
    }
    else if (y==0) {
        neighbors.push_back(this->position_to_domain_index(x,100));
    }
    // etc..

    return neighbors;
}

int Domains::total_size() {
    int size = 0;

    for (auto i=0 ; i<100*100 ; i++) {
        size += this->domain_matrix[i].size();
    }

    return size;
}
