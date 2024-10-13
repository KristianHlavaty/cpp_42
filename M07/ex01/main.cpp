#include <iostream>
#include "Iter.hpp"

// A functor is pretty much just a class which defines the operator(). That lets you create objects which "look like" a function
class PrintWithBrackets
{
	public:
	// overloading operator() so i can use it like a function
		void operator()(int x) const
		{
			std::cout << "[" << x << "] ";
		}
};

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

	// get the number of elements in the array
	size_t intArrLen = sizeof(intArr) / sizeof(intArr[0]);
	size_t doubleArrLen = sizeof(doubleArr) / sizeof(doubleArr[0]);

	// maybe use something like size of array for len
	std::cout << "Int array: ";
	iter(intArr, intArrLen, printInt);
	std::cout << std::endl;

	std::cout << "Double array: ";
	iter(doubleArr, doubleArrLen, printDouble);
	std::cout << std::endl;



	std::cout << "Int array with template function: ";
	iter(intArr, intArrLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "Double array with template function: ";
	iter(doubleArr, doubleArrLen, printElement<double>);
	std::cout << std::endl;

	std::cout << "Int array with template function and negative len: ";
	iter(intArr, -1, printElement<int>);
	std::cout << std::endl;

	PrintWithBrackets printWithBrackets;
	std::cout << "Int array with functor: ";
	iter(intArr, intArrLen, printWithBrackets);
	std::cout << std::endl;
}