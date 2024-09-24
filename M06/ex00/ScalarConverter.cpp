#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _literal("c")
{
	// std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &literal) : _literal(literal)
{
	// TODO add exceptions for checking the format
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _literal(other._literal)
{

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		// probably nothing
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

// Exceptions
// TODO maybe provide right format
const char *ScalarConverter::LiteralInWrongFormat::what() const throw()
{
	return "Literal is in wrong format";
}