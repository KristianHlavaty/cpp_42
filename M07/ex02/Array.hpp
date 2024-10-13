#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <exception>

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
		
		// allowing retrieving or modifying array elements at a specific index
		T &operator[](unsigned int index); // subscript operator
		// same but only retrieving elements because of const
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
// #include "Array.tpp" // could uncomment and put into .tpp but Intellisense is screaming so solve later

// default constructor
template <typename T>
Array<T>::Array() : elements(NULL), n(0) {}

// parameterized constructor
template <typename T>
Array<T>::Array(unsigned int n) : n(n)
{
	elements = new T[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		elements[i] = T(); // init elements to default values
	}
}

// copy constructor
template <typename T>
Array<T>::Array(const Array &other) : n(other.n)
{
	elements = new T[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		elements[i] = other.elements[i];
	}
}

// copy assignment operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] elements; // freeing old elements
		n = other.n;
		elements = new T[n];
		for (unsigned int i = 0; i < n; ++i)
		{
			elements[i] = other.elements[i];
		}
	}
	return *this;
}

// destructor
template <typename T>
Array<T>::~Array()
{
	delete[] elements;
}

// subscript operator
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= n)
		throw OutOfBounds();
	return elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= n)
		throw OutOfBounds();
	return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return n;
}

// exceptions
template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return "Index out of bounds";
}
#endif