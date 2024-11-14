#include "Span.hpp"

Span::Span()
{
	
}

Span::Span(unsigned int n) : _n(n)
{

}

Span::~Span()
{

}

Span::Span(const Span &other)
{

}

Span &Span::operator=(const Span &other)
{

}

void Span::addNumber(int number)
{

}

void Span::addALotOfNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{

}

long Span::shortestSpan()
{

}

long Span::longestSpan()
{

}

const char *Span::NoNumbers::what() const throw()
{
	return "no numbers, no span, what did you expect HMMMMM?";
}

const char *Span::FullSpan::what() const throw()
{
	return "Span is full";
}