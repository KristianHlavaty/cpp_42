#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int _n; // max number of integers
		Span(); // probably dont have to be public
		std::vector<int> _numbers;
	public:
		Span(unsigned int n); // parameterized constructor
		Span(const Span &other); // copy constructor
		Span &operator=(const Span &other); // copy assignment operator
		~Span();
		void addNumber(int number);
		long shortestSpan(); // I know that using long is a bit overkill
		long longestSpan();

		void addALotOfNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		// exceptions
		class NoNumbers : public std::runtime_error
		{
			public:
				NoNumbers();
		};
		class FullSpan : public std::runtime_error
		{
			public:
				FullSpan();
		};
};

#endif