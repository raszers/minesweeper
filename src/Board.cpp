#include "Board.hpp"
#include <iostream>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

Board::Board()
        : dimensions(Dimensions{10,10})
        , numberOfMines(5)
    {}

Board::Board(
    const Settings& settings)
        : dimensions(Dimensions{settings.boardHeight, settings.boardWidth})
        , numberOfMines(settings.numberOfMines)
    {}
Board::~Board(){};

void Board::createCellArray()
{
    cellArray = std::vector(dimensions.height, std::vector<Cell>(dimensions.width));
    fillWithMines();
}

void Board::fillWithMines()
{
    std::srand ( unsigned ( std::time(0) ) );
    const int numberOfCells = dimensions.height * dimensions.width;
    std::vector<int> cellsVector;
    for(int i = 0; i < numberOfCells; i++)
    {
        cellsVector.emplace_back(i);
    }
    std::random_shuffle(cellsVector.begin(), cellsVector.end());
    cellsVector.resize(numberOfMines);
    for(int i = 0; i < cellsVector.size(); i++)
    {
        int y = cellsVector[i] / dimensions.width;
        int x = cellsVector[i] % dimensions.width;
        cellArray[y][x].mine = true;
        updateNeigborsAfterMineAdded(y,x);
    }
}

void Board::updateNeigborsAfterMineAdded(int y, int x)
{
    for(int i = x-1; i < x+2; i ++)
    {
        for(int j = y-1; j < y+2; j++)
        {
            if(i >= 0 and i < dimensions.width and j >= 0 and j < dimensions.height and not (x == i and y == j))
            {
                cellArray[j][i].neighboringMines++;
            }
        }
    }
}

Cell& Board::getCell(const int y, const int x)
{
    return cellArray[y][x];
}

std::optional<bool> Board::handleInput(const int y, const int x)
{
    if(cellArray[y][x].mine)
    {
        {
            std::cout << "Ya LOST board" << std::endl;
            cellArray[y][x].revealed = true;
            return false;
        }
    }
    revealCell(y, x);
    return checkVictoryCondition();
}

void Board::revealCell(const int y, const int x)
{
    Cell& cell = cellArray[y][x];
    if(cell.revealed)
    {
        std::cout << "Cell already revealed" << std::endl;
        return;
    }
    cell.revealed = true;
    revealedCells++;
    if(cell.neighboringMines == 0)
    {
        for(int i = x-1; i < x+2; i ++)
            {
                for(int j = y-1; j < y+2; j++)
                {
                    if(i >= 0 and i < dimensions.width and j >= 0 and j < dimensions.height and not (x == i and y == j))
                    {
                        revealCell(j,i);
                    }
                }
            }
    }
}

std::optional<bool> Board::checkVictoryCondition()
{
    const int cellsToReveal = dimensions.height * dimensions.width - numberOfMines;
    if(revealedCells < cellsToReveal)
    {
        return std::nullopt;
    }
    if(revealedCells > cellsToReveal)
    {
        std::cout << "cos nie poszlo" << std::endl;
        return false;
    }
    return true;
}
