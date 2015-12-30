#include <chrono>
#include <random>

#include "Random/MersenneTwister.hpp"


MersenneTwister::MersenneTwister() {
    unsigned long seed = std::chrono::system_clock::now().time_since_epoch().count();
    this->generator = new std::mt19937_64(seed);
    this->normal_distribution = new std::normal_distribution<double>(0.0, 1.0);
    this->uniform_real_distribution = new std::uniform_real_distribution<double>(0.0, 1.0);
}

MersenneTwister::~MersenneTwister() {
    delete this->generator;
    delete this->normal_distribution;
    delete this->uniform_real_distribution;
}

double MersenneTwister::normal() {
    return (*this->normal_distribution)(*this->generator);
}

double MersenneTwister::unit() {
    return (*this->uniform_real_distribution)(*this->generator);
}

