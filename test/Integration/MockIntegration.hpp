#ifndef MOCKINTEGRATION_H
#define MOCKINTEGRATION_H

#include "gmock/gmock.h"
#include "Integration/Integration.hpp"

class MockIntegration : public Integration {
  public:
  MOCK_METHOD0 ( run, void() );
};

#endif
