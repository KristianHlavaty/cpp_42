#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl harl;

	std::cout << "DEBUG level complaint:" << std::endl;
    harl.complain("DEBUG");

	std::cout << "\nINFO level complaint:" << std::endl;
    harl.complain("INFO");

	std::cout << "\nWARNING level complaint:" << std::endl;
    harl.complain("WARNING");

	std::cout << "\nERROR level complaint:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nInvalid level complaint:" << std::endl;
    harl.complain("INVALID");

	return 0;
}
