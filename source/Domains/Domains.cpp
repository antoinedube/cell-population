#include <iostream>
#include <vector>

#include "Domains/Domains.hpp"
#include "Models/Particle.hpp"


Domains::Domains() {
    this->domain_matrix = new std::vector< std::vector< std::vector<Particle *> > >();
}

Domains::~Domains() {
    delete this->domain_matrix;
}

void Domains::add(Particle *particle) {
    std::cout << "add: " << particle->id << std::endl;
}

void Domains::update(Particle *particle) {
    std::cout << "update: " << particle->id << std::endl;
}

void Domains::remove(Particle *particle) {
    std::cout << "remove: " << particle->id << std::endl;
}

std::vector<Particle *> Domains::get_neighboring_particles(Particle *particle) {
    std::cout << "Get neighboring particles" << std::endl;
    // https://stackoverflow.com/questions/18147400/best-way-to-append-vector-to-vector

    std::vector<Particle *> neighboring_particles;
    neighboring_particles.push_back(particle);

    return neighboring_particles;
}
