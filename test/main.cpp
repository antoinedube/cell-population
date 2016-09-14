#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "test/Domains/TestDomains.hpp"
#include "test/Integration/TestIntegration.hpp"
#include "test/Models/TestCell.hpp"
#include "test/Models/TestParticle.hpp"
#include "test/Models/TestSystem.hpp"
#include "test/Models/TestSystemBuilder.hpp"
#include "test/Random/TestMersenneTwister.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
