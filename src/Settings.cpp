#include "Settings.hpp"
#include <iostream>

Settings::Settings(int argc, char *argv[])
{
    boardHeight = 10;
    boardWidth = 10;
    numberOfMines = 5;
    switch(argc)
    {
        case 1:
            break;
        case 3:
            boardHeight = std::stoi(argv[1]);
            boardWidth = std::stoi(argv[2]);
            break;
        case 4:
            boardHeight = std::stoi(argv[1]);
            boardWidth = std::stoi(argv[2]);
            numberOfMines = std::stoi(argv[3]);
            break;
        default:
            std::cout << "Wrong!!!" << std::endl;
    }
}
Settings::~Settings(){}
