#pragma once
#include "Board.hpp"
#include "Settings.hpp"

class Runner
{
    public:
        Runner();
        Runner(const Settings&);
        ~Runner();
        void initialize();
        int run();

    private:
        const Settings& settings;
        Board board;
        bool victory{false};

        void printField();
};
