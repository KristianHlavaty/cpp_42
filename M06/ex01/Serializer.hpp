#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:

		Serializer(); // default constructor
		Serializer(const Serializer &other); // copy constructor
		Serializer &operator=(const Serializer &other);
		~Serializer(); // destructor
	
	public:
		// It takes a pointer and converts it to the unsigned integer type uintptr_t.
		uintptr_t serialize(Data* ptr);
		// add errors
};
#endif