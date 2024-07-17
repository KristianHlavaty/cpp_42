#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Assignation operator overload
		~Fixed(); // Destructor

		Fixed(const int value); // Constructor from integer
		Fixed(const float value); // Constructor from float

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const; // Converts to float
		int toInt(void) const; // Converts to int

		// Overload the << operator

		// friend function
		// allows the overloaded << operator function to access the private members of the Fixed class
		// << operator needs access to the private member _fixedPointValue
		// to convert and output the fixed-point value as a float.
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
    	Fixed operator/(const Fixed& other) const;

		// Increment/decrement operators
		Fixed& operator++(); // Pre-increment
		Fixed operator++(int); // Post-increment
		Fixed& operator--(); // Pre-decrement
		Fixed operator--(int); // Post-decrement;

		// Min and Max functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

#endif