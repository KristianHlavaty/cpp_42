#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"
#include <string> // also includes exception there

class Serializer
{
	private:

		Serializer(); // default constructor
		Serializer(const Serializer &other); // copy constructor
		Serializer &operator=(const Serializer &other);
		~Serializer(); // destructor
	
	public:
		// It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(Data* ptr);
		// It takes an unsigned integer parameter and converts it to a pointer to Data.
		static Data* deserialize(uintptr_t raw);

		class SerializationError : public std::exception
		{
			private:
				std::string _message;
			public:
				SerializationError(const std::string &message) : _message(message) {}
				virtual const char *what() const throw();

				// need this here to fix:
				// error: exception specification of overriding function is more lax than base version
				virtual ~SerializationError() throw() {};
		};
};
#endif