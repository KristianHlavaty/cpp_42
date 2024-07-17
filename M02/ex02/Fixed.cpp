#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// copy constructor to directly initialize the _fixedPointValue member
// ensures the copy assignment operator is not called during construction
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}

	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	// bit shift
	// can handle fractions up to 1/256th (2^8)
	_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
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

// Comparison operators

bool Fixed::operator>(const Fixed& other) const
{
	return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
	return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
	return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return _fixedPointValue != other._fixedPointValue;
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long long product = static_cast<long long>(this->_fixedPointValue) * other._fixedPointValue;
    result.setRawBits(static_cast<int>(product >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._fixedPointValue == 0)
	{
        std::cerr << "Error: Division by zero!" << std::endl;
        exit(1);  // Simple error handling for division by zero
    }
    Fixed result;
    long long dividend = static_cast<long long>(this->_fixedPointValue) << _fractionalBits;
    result.setRawBits(static_cast<int>(dividend / other._fixedPointValue));
    return result;
}

// Increment/Decrement operators
Fixed& Fixed::operator++()
{  // Pre-increment
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{  // Post-increment
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--()
{  // Pre-decrement
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{  // Post-decrement
    Fixed temp(*this);
    _fixedPointValue--;
    return temp;
}

// Min and Max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    else
        return b;
}