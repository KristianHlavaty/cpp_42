#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor to directly initialize the _fixedPointValue member
// ensures the copy assignment operator is not called during construction
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	// bit shift
	// can handle fractions up to 1/256th (2^8)
	_fixedPointValue = intValue << _fractionalBits;
}

// _fractionalBits is 8, so (1 << 8) is equivalent to 2^8 = 256
// Binary of 256: 100000000.
// Right shift by 8 positions: 00000001.
// Decimal result: 1.
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// whole point here is By shifting an integer value left by 8 bits, we multiply it by 2^8(256).
// This allows to represent fractional parts accurately

// A fixed-point number is essentially a decimal number with a predetermined and fixed number
// of decimal places (fractional bits).