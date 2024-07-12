#include "Replace.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
        std::cerr << "Usage: " << av[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
	{
        std::cerr << "Error: The string to replace (s1) cannot be empty." << std::endl;
        return 1;
    }

    Replace replacer;
    if (!replacer.replaceInFile(filename, s1, s2))
	{
        std::cerr << "Error: Failed to process the file." << std::endl;
        return 1;
    }

    return 0;
}