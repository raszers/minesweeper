#include "Runner.hpp"
#include <iostream>
#include <optional>
#include "InputMode.hpp"

namespace
{
void clearConsole() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

InputMode decodeInputMode(char c)
{
    switch(c)
    {
        case 'g':
            return InputMode::guess;
        case 'f':
            return InputMode::flag;
        default:
            return InputMode::unknownMode;
    }
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
    char mode;
    int x, y;
    std::optional<bool> gameOver;
    while(not gameOver)
    {
        std::cout << "Insert [mode - f or g] [column] [row]" << std::endl;
        std::cin >> mode >> x >> y;
        if(y > 0 and y <= settings.boardHeight and x > 0 and x <= settings.boardWidth)
        {
            const InputMode inputMode = decodeInputMode(mode);
            gameOver = board.handleInput(y-1, x-1, inputMode);
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
