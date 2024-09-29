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

uintptr_t Serializer::serialize(Data* ptr)
{
	if (ptr == NULL)
	{
		throw SerializationError("Cannot serialize a null pointer.");
	}
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = reinterpret_cast<Data*>(raw);
	// making sure that deserialized data is valid
	if (ptr == NULL)
	{
		throw SerializationError("Deserialized pointer is null.");
	}
	return ptr;
}

// exceptions
const char *Serializer::SerializationError::what() const throw()
{
	return _message.c_str();
}

// i think that point of the exercise is to 
// know how to convert object(structure in this case) into
// format that can be easily stored or transmitted and 
// reconstructed later