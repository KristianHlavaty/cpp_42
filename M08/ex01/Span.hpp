#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

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
		class NoNumbers : public std::exception
		{
			public:
				const char *what() const throw();
				// return "no numbers, no span, what did you expect HMMMMM?"
		};
		class FullSpan : public std::exception
		{
			public:
				const char *what() const throw();
				//return "Span is full";
		};
		
};

#endif