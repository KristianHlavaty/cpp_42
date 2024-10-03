#include "Whatever.hpp"

Whatever::Whatever()
{
}

Whatever::Whatever(const Whatever &other)
{
	(void)other;
}

Whatever &Whatever::operator=(const Whatever &other)
{
	(void)other;
	return *this;
}

Whatever::~Whatever()
{
}