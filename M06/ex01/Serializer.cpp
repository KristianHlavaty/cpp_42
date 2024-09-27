#include "Serializer.hpp"

// orthodox canonical section
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	// suppressing warning
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	// suppressing warning
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
}

//
