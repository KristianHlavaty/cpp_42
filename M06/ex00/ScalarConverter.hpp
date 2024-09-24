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
		const std::string _literal;
		ScalarConverter(); // default constructor

	public:
		ScalarConverter(const std::string &literal); // constructor
		ScalarConverter(const ScalarConverter &other); // copy constructor
		ScalarConverter &operator=(const ScalarConverter &other); // copy assignment operator
		virtual ~ScalarConverter();

		std::string getLiteral() const; // probably cant have this thanks to subject ? maybe

		// Write a class ScalarConverter that will contain only one static method "convert
		// only one?

		virtual void convert(const std::string &literal) const = 0;

		// excpetions
		// TODO

		class LiteralInWrongFormat : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif