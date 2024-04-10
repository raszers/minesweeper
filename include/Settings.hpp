#pragma once

class Settings
{
    public:
        Settings() = delete;
        Settings(int, char**);
        ~Settings();

        int boardHeight;
        int boardWidth;
        int numberOfMines;
};
