#pragma once
#include <iosfwd>

struct Cell
{
    bool mine{false};
    int neighboringMines{0};
    bool revealed{false};
};
std::ostream& operator<<(std::ostream&, const Cell&);

