#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
	private:
		unsigned int n; // max number of integers
		Span(); // probably dont have to be public
	
	public:
		Span(unsigned int n); // parameterized constructor
		Span(const Span &other); // copy constructor
		Span &operator=(const Span &other); // copy assignment operator
		~Span();
		void addNumber();

};

#endif