#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	int intArr[] = {-100, 2, 3, 3, 5, 6};
	int size = sizeof(intArr) / sizeof(intArr[0]);

	// intArr 			-> pointer to first elem.
	// intArr + size 	-> pointer to one past the end
	std::vector<int> intVector(intArr, intArr + size);
	
	// testing if the values are there
	std::cout << "should print 6 numbers" << std::endl;
	for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	// Vector test
	std::cout << std::endl;
	std::cout << "Testing vector with number that is in the Array" << std::endl;
	try
	{
		int* result = easyFind(intVector, 2);
		std::cout << "Found value: " << *result << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Testing vector with number that is negative" << std::endl;
	try
	{
		int* resultNeg = easyFind(intVector, -100);
		std::cout << "Found value: " << *resultNeg << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Testing vector with number that is there twice" << std::endl;
	try
	{
		int* resultTwice = easyFind(intVector, 3);
		std::cout << "Found value: " << *resultTwice << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::vector<int> emptyVector;
	std::vector<int> singleElementVector;
	singleElementVector.push_back(5);
	std::cout << std::endl;
	std::cout << "Vector Error Section" << std::endl;
	std::cout << std::endl;
	std::cout << "Testing empty vector" << std::endl;
	try
	{
		int* emptySearch = easyFind(emptyVector, 3);
		std::cout << "Found value: " << *emptySearch << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Testing value in single Elem Vector" << std::endl;
	try
	{
		int* singleSearch = easyFind(singleElementVector, 5);
		std::cout << "Found value: " << *singleSearch << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Testing value not in single Elem Vector" << std::endl;
	try
	{
		int* singleSearchNotThere = easyFind(singleElementVector, 3);
		std::cout << "Found value: " << *singleSearchNotThere << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}