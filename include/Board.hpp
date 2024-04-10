#pragma once
#include <vector>
#include <optional>
#include "Settings.hpp"
#include "Cell.hpp"

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
        std::optional<bool> handleInput(const int, const int);
        Cell& getCell(const int, const int);

    private:
        Dimensions dimensions{};
        std::vector<std::vector<Cell>> cellArray{};
        int numberOfMines{};
        int revealedCells{0};

        void updateNeigborsAfterMineAdded(int, int);
        void revealCell(const int, const int);
        std::optional<bool> checkVictoryCondition();
};
