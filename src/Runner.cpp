#include "Runner.hpp"
#include <iostream>
#include <optional>

namespace
{
void clearConsole() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
} //namespace

Runner::Runner(const Settings& settings_)
    : settings(settings_)
    , board(Board(settings_)){};

Runner::~Runner(){};

void Runner::initialize()
{
    board.createCellArray();
}

int Runner::run()
{
    printField();
    int x, y;
    std::optional<bool> gameOver;
    while(not gameOver)
    {
        std::cout << "Insert Column [space] Row " << std::endl;
        std::cin >> x >> y;
        if(y > 0 and y <= settings.boardHeight and x > 0 and x <= settings.boardWidth)
        {
            gameOver = board.handleInput(y-1,x-1);
            printField();
        }
        else
        {
            printField();
            std::cout << "[" << x << "][" << y << "] Out of bounds" << std::endl;
        }
    }
    if(gameOver.value())
    {
        std::cout << "You won" << std::endl;
    }
    else
    {
        std::cout << "Ya LOST" << std::endl;
    }
    return 0;
}

void Runner::printField()
{
    clearConsole();
    std::cout << "   |";
    for(int i = 1; i <= settings.boardWidth; i++)
    {
        if(i < 10)
        {
            std::cout << " " << i << " |";
        }
        else 
        {
            std::cout << " " << i << "|";
        } 
        
    }
    std::cout << std::endl << "----";

    for(int i = 0; i < settings.boardWidth; i++)
    {
        std::cout << "----";
    }
    std::cout << std::endl;
    for(int i = 0; i < settings.boardHeight; i++)
    {
        if(i < 9)
        {
            std::cout << i  + 1 << "  |";
        }
        else 
        {
            std::cout << i + 1 << " |";
        } 
        for(int j = 0; j < settings.boardWidth; j++)
        {
            const auto& cell = board.getCell(i,j);
            std::cout << " " << cell << " |";
        }
        std::cout << std::endl;
        std::cout << "----";
        for(int j = 0; j < settings.boardWidth; j++)
        {
            std::cout << "----";
        }
        std::cout << std::endl;
    }
}
