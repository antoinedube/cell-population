#ifndef MOCKDOMAINS_H
#define MOCKDOMAINS_H

#include "gmock/gmock.h"

#include "domains/domains.hpp"


class MockDomains : public Domains {
public:
    MOCK_METHOD1(get_neighboring_particles, std::vector<Particle *>(Particle *particle));
    MOCK_METHOD1(add, void(Particle *particle));
    MOCK_METHOD1(remove, void(Particle *particle));
    MOCK_METHOD1(vector_at, std::vector<Particle *>(int i));
    MOCK_METHOD2(position_to_domain_index, int(int x, int y));
    MOCK_METHOD2(indices_of_neighboring_domains, std::vector<int>(int x, int y));
    MOCK_METHOD0(total_size, int());
};

#endif
