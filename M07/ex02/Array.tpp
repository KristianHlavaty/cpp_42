// #include "Array.hpp"


// // default constructor
// template <typename T>
// Array<T>::Array() : elements(NULL), n(0) {}

// // parameterized constructor
// template <typename T>
// Array<T>::Array(unsigned int n) : n(n)
// {
// 	elements = new T[n];
// 	for (unsigned int i = 0; i < n; ++i)
// 	{
// 		elements[i] = T(); // init elements to default values
// 	}
// }

// // copy constructor
// template <typename T>
// Array<T>::Array(const Array &other) : n(other.n)
// {
// 	elements = new T[n];
// 	for (unsigned int i = 0; i < n; ++i)
// 	{
// 		elements[i] = other.elements[i];
// 	}
// }

// // copy assignment operator
// template <typename T>
// Array<T> &Array<T>::operator=(const Array &other)
// {
// 	if (this != &other)
// 	{
// 		delete[] elements; // freeing old elements
// 		n = other.n;
// 		elements = new T[n];
// 		for (unsigned int i = 0; i < n; ++i)
// 		{
// 			elements[i] = other.elements[i];
// 		}
// 	}
// 	return *this;
// }

// // destructor
// template <typename T>
// Array<T>::~Array()
// {
// 	delete[] elements;
// }

// // subscript operator
// template <typename T>
// T &Array<T>::operator[](unsigned int index)
// {
// 	if (index >= n)
// 		throw OutOfBounds();
// 	return elements[index];
// }

// template <typename T>
// const T &Array<T>::operator[](unsigned int index) const
// {
// 	if (index >= n)
// 		throw OutOfBounds();
// 	return elements[index];
// }

// template <typename T>
// unsigned int Array<T>::size() const
// {
// 	return n;
// }

// // exceptions
// template <typename T>
// const char *Array<T>::OutOfBounds::what() const throw()
// {
// 	return "Index out of bounds";
// }