#include <iostream>
#include "Array.hpp"

template <typename T>
void printElement(const T &x)
{
	std::cout << x << " ";
}


int main()
{
	try
	{
		std::cout << "Basic tests: " << std::endl;
		// testing default constructor
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		// testing parameterized constructor with size
		Array<int> intArray(6);
		std::cout << "Integer array size: " << intArray.size() << std::endl;

		// filling array with values
		for (unsigned int i = 0; i < intArray.size(); i++)
		{
			intArray[i] = i + 1;
		}

		// just printing them
		std::cout << "Integer array elements: ";
		for (unsigned int i = 0; i < intArray.size(); i++)
		{
			printElement(intArray[i]);
		}
		std::cout << std::endl;

		// testing the copy constructor
		Array<int> copyArray(intArray);
		std::cout << "Copied array elements: ";
		for (unsigned int i = 0; i < copyArray.size(); i++)
		{
			printElement(copyArray[i]);
		}
		std::cout << std::endl;

		// here modifying original array and seeing if the copy is affected or not
		intArray[0] = 100;
		std::cout << "Modified original array: ";
		for (unsigned int i = 0; i <intArray.size(); i++)
		{
			printElement(intArray[i]);
		}
		std::cout << std::endl;

		// copied array after modif the original
		std::cout << "Copied array after modification of original: ";
		for (unsigned int i = 0; i <copyArray.size(); i++)
		{
			printElement(copyArray[i]);
		}
		std::cout << std::endl;
		std::cout << std::endl;

		// TESTING COMPLEX TYPE
		std::cout << "Testing a complex type: " << std::endl;
		Array<std::string> strArray(3);
		strArray[0] = "Dobrej";
		strArray[1] = "cus";
		strArray[2] = "ahoj";
		std::cout << "String array elements: ";
		for(unsigned int i = 0; i < strArray.size(); i++)
		{
			printElement(strArray[i]);
		}
		std::cout << std::endl;
		std::cout << std::endl;

		// testing out of bounds
		std::cout << "Testing a throw if out of bounds: " << std::endl;
		std::cout << "Attempting to access out of bounds index: ";
		std::cout << intArray[10] <<std::endl; // should throw
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}