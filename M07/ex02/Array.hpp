#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T* elements;
		unsigned int n;
	
	public:
		Array(); // default constructor
		Array(unsigned int n); // parameterized constructor
		Array(const Array &other); // copy constructor
		Array &operator=(const Array &other); // copy assignment operator
		~Array(); // destructor
		
		T &operator[](unsigned int index); // subscript operator
		const T &operator[](unsigned int index) const; // const subscript operator
		unsigned int size() const; // size function

		// exceptions
		class OutOfBounds : public std::exception
		{
			public:
				const char *what() const throw();
		};

};
// should be down otherwise it will not find the class
// i can put everything in header
#include "Array.tpp"

#endif