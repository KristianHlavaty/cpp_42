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

	// identify by pointer
	std::cout << "Identify by pointer: ";
	identify(base);

	// identify by reference
	std::cout << "Identify by reference: ";
	identify(*base);

	delete base;

	return 0; // probably do try catch, but we will see
}