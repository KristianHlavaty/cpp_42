#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a; 
	Fixed b(a); // Creates a new object as a copy of an existing object
	Fixed c; 

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;

}