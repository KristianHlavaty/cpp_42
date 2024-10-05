#include <iostream>
#include "Iter.hpp"

void printInt(const int &x)
{
	std::cout << x << " ";
}

void printDouble(const double &x)
{
	std::cout << x << " ";
}

template <typename T> 
void printElement(const T &x)
{
	std::cout << x << " ";
}

int main()
{
	int intArr[] = {1, 2, 3, 4, 5, 6};
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};


	// maybe use something like size of array for len
	std::cout << "Int array: ";
	iter(intArr, 6, printInt);
	std::cout << std::endl;

	std::cout << "Double array: ";
	iter(doubleArr, 6, printDouble);
	std::cout << std::endl;

	std::cout << "Int array with template function and negative len: ";
	iter(intArr, -1, printElement<int>);
	std::cout << std::endl;

	std::cout << "Int array with template function: ";
	iter(intArr, 6, printElement<int>);
	std::cout << std::endl;

	std::cout << "Double array with template function: ";
	iter(doubleArr, 6, printElement<double>);
	std::cout << std::endl;
}