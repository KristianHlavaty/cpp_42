#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

// As this class doesn’t need to store anything at all, this class must not be instanciable by
// users.

// So probably abstract class and after that a class for every type char, int, float, double,
// i suspect

// one static method "convert

#include <iostream>

class ScalarConverter
{
	private:
		// _ before variable is used only if it is a private member of the class
		// if it is a parameter passed to the function, no underscore

		
		// don't need to maintain any internal state and only need to perform a task
		// achieving non-instantiable state by just making constructor private
		ScalarConverter(); // default constructor
		ScalarConverter(const ScalarConverter &other); // copy constructor
		ScalarConverter &operator=(const ScalarConverter &other); // copy assignment operator
		~ScalarConverter(); // destructor

		// converting
		static void convertToChar(double value);
		static void convertToInt(double value);
		static void convertToFloat(double value);
		static void convertToDouble(double value);

		// checking pseudo literals
		// "You have to handle these pseudo literals as well (you know, for science): -inff, +inff
		// and nanf."
		static bool isPseudoLiteral(const std::string &lireal);
	public:

		static void convert(const std::string &literal);
		// excpetions
		// TODO more

		class LiteralInWrongFormat : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// class can be made abstract by having at least one pure virtual method (= 0)
// used when you want to enforce that derived classes must implement certain functionality

#endif