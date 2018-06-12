#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "test/domains/test-domains.hpp"
#include "test/integration/test-integration.hpp"
#include "test/models/test-cell.hpp"
#include "test/models/test-particle.hpp"
#include "test/models/test-system.hpp"
#include "test/models/test-system-builder.hpp"
#include "test/random/test-mersenne-twister.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
