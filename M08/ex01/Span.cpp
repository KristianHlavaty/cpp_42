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
	if (_numbers.size() < 2)
	{
		throw NoNumbers();
	}

	// sorting allows me to make adjacent pairs have the closest values
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	// i think that anything bigger than unsigned int would be always fine
	// could initialize to UINT_MAX also
	long shortestSpan = LONG_MAX; 

	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		long span = sortedNumbers[i] - sortedNumbers[i - 1];
		if(span < shortestSpan)
		{
			shortestSpan = span;
		}
	}
	return (shortestSpan);
}

long Span::longestSpan()
{
	long a = 0;
	return a;
}

// exceptions
Span::NoNumbers::NoNumbers() : std::runtime_error("no numbers, no span, what did you expect HMMMMM?")
{

}

Span::FullSpan::FullSpan() : std::runtime_error("Span is full")
{

}