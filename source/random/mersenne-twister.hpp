#ifndef MERSENNETWISTER_HPP
#define MERSENNETWISTER_HPP

#include <random>


class MersenneTwister {
public:
    MersenneTwister();
    virtual ~MersenneTwister();
    virtual double normal();
    virtual double unit();

private:
    std::mt19937_64 *generator;
    std::normal_distribution<double> *normal_distribution;
    std::uniform_real_distribution<double> *uniform_real_distribution;
};

#endif
