#pragma once
#include <vector>
#include "Settings.hpp"
#include "Cell.hpp"
#include "InputMode.hpp"
#include "Result.hpp"

struct Dimensions
{
    int height{};
    int width{};
};

class Board
{
    public:
        Board();
        Board(const Settings&);
        ~Board();
        void createCellArray();
        void fillWithMines();
        Result handleInput(const int, const int, const InputMode);
        Cell& getCell(const int, const int);

    private:
        Dimensions dimensions{};
        std::vector<std::vector<Cell>> cellArray{};
        int numberOfMines{};
        int revealedCells{0};

        void updateNeigborsAfterMineAdded(int, int);
        void revealCell(const int, const int);
        Result checkVictoryCondition();
};
