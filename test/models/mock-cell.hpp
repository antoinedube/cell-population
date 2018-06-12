#ifndef MOCKCELL_H
#define MOCKCELL_H

#include "gmock/gmock.h"

#include "models/cell.hpp"


class MockCell : public Cell {
    public:
    MOCK_METHOD0 ( execute, void() );
};

#endif
