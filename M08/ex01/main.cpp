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
	try
	{
		copiedEmptySpan.longestSpan(); // should throw
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
	try
	{
		Span single(1);
		single.addNumber(666);
		std::cout << "Longest span: " << single.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	// some numbers
	std::cout << std::endl;
	Span spans(5);
	spans.addNumber(10);
	spans.addNumber(13);
	spans.addNumber(300);
	spans.addNumber(-100);
	spans.addNumber(0);
	std::cout << "just couple of numbers" << std::endl;
	try
	{
		std::cout << "Shortest span: " << spans.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Longest span: " << spans.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	Span spansDup(5);
	spansDup.addNumber(10);
	spansDup.addNumber(10);
	spansDup.addNumber(300);
	spansDup.addNumber(-100);
	spansDup.addNumber(0);
	std::cout << std::endl;
	std::cout << "duplicates" << std::endl;
	try
	{
		std::cout << "Shortest span: " << spans.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Longest span: " << spans.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// duplicates
	
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