#include <iostream>
#include <cstdlib> // rand() srand()
#include <ctime> // time()
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int random = rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

void identify(Base &p)
{
	bool identified = false;

	if (!identified)
	{
		try
		{
			A& a = dynamic_cast<A&>(p);
			std::cout << "A" << std::endl;
			(void)a;
			identified = true;
		}
		catch(std::exception &e) 
		{
		}
	}

	if (!identified)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
			identified = true;
		}
		catch(std::exception &e) 
		{
		}
	}

	if (!identified)
	{
		try
		{
			C& c = dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
			(void)c;
			identified = true;
		}
		catch(std::exception &e)
		{
		}
	}
	
	if (!identified)
	{
		std::cout << "Unknown type" << std::endl;
	}
}