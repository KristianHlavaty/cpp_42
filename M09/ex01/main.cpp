#include <iostream>
#include "RPN.hpp"

int main (int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Usage: ./RPN \"expression\"" <<std::endl;
		return 1;
	}

	RPN rpn;
	std::string input = av[1];
	if(rpn.isValidInput(input))
	{
		std::cout << "valid RPN expression" <<std::endl;
	}
	else
	{
		std::cerr << "invalid RPN expression" << std::endl;
	}
	
}