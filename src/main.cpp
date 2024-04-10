#include "../include/Board.hpp"
#include "../include/Runner.hpp"
#include <string>

int main(int argc, char *argv[])
{
    const Settings settings(argc, argv);
    Runner runner(settings);
    runner.initialize();
    runner.run();
    return 0;
}
