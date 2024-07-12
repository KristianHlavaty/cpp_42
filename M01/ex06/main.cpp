#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
	{
        std::cerr << "Usage: " << av[0] << " <log level>" << std::endl;
        return 1;
    }

    Harl harl;
    std::string level = av[1];

    harl.filter(level);

    return 0;
}
