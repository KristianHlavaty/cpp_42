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

Span::Span(const Span &other) : _n(other._n), _numbers(other._numbers)
{

}

Span &Span::operator=(const Span &other)
{
	if(this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	_numbers.push_back(number);
}

void Span::addALotOfNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for(std::vector<int>::iterator it = begin; it != end; ++it)
	{
		if(_numbers.size() >= _n)
		{
			throw FullSpan();
		}
		_numbers.push_back(*it);
	}
}

long Span::shortestSpan()
{
	long a = 0;
	return a;
}

long Span::longestSpan()
{
	long a = 0;
	return a;
}

// exceptions
const char *Span::NoNumbers::what() const throw()
{
	return "no numbers, no span, what did you expect HMMMMM?";
}

const char *Span::FullSpan::what() const throw()
{
	return "Span is full";
}