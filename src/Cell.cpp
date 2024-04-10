#include "Cell.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& str, const Cell& cell)
{
    if(not cell.revealed)
    {
        return str << " "; 
    }
    if(cell.mine)
    {
        return str << "X";
    }
    return str << cell.neighboringMines;

}
