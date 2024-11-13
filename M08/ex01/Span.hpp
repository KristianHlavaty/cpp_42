#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
	private:
		unsigned int n;
		Span(); // probably dont have to be public, maybe
				// default constructor
	
	public:
		Span(unsigned int n); // parameterized constructor
		Span(const Span &other); // copy constructor
		Span &operator=(const Span &other); // copy assignment operator
		~Span();


};

#endif