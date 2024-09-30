#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	Base* base = generate();

	if (base == NULL)
	{
		std::cerr << "Failed to generate a valid Base object." << std::endl;
	}
	// identify by pointer
	std::cout << "Identify by pointer: ";
	try
	{
		identify(base);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// identify by reference
	std::cout << "Identify by reference: ";
	try
	{
		identify(*base);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete base;

	return 0;
}