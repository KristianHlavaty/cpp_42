#include <iostream>
#include <vector>

#include "Span.hpp"

int main()
{

	// testing copy constructor and assignment operator
	Span sp1(5);
	sp1.addNumber(10);
	sp1.addNumber(23);

	std::cout << "Testing copying" << std::endl;
	std::cout << std::endl;
	// copy
	Span sp2 = sp1;
	std::cout << "sp2 contents after copy: " << sp2.shortestSpan() << std::endl;

	// assignment
	Span sp3(5);
	sp3 = sp1;
	std::cout << "sp3 contents after assig: " << sp3.shortestSpan() << std::endl;
	
	// just testing empty
	Span emptySpan(10);
	Span copiedEmptySpan = emptySpan;
	try
	{
		copiedEmptySpan.shortestSpan(); // should throw
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// span
	std::cout << "span section" << std::endl;
	std::cout << std::endl;
	std::cout << "only one number in span" << std::endl;
	try
	{
		Span single(1);
		single.addNumber(666);
		std::cout << "Shortest span: " << single.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	Span span(10);
	int intArr[] = {-100, 2, 3, 3, 5, 6};
	int size = sizeof(intArr) / sizeof(intArr[0]);
	std::vector<int> intVector(intArr, intArr + size);
	// ADD SHORT SPAN TESTS NOT JUST FOR BIG NUMBERS BUT BASIC ALSO
	// both with a lot of numbers
	std::cout << std::endl;
	std::cout << "a lot of numbers" << std::endl;
	Span bigSpan(10001);
	std::vector<int> bigVector(10001);
	srand(static_cast<unsigned int>(time(0))); // seed for rand
	for (int i = 0; i < 10001; ++i)
	{
		bigVector[i] = rand();
	}
	try
	{
		bigSpan.addALotOfNumbers(bigVector.begin(), bigVector.end());
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	
	return 0;
}