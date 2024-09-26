#include "ScalarConverter.hpp"
#include <string>
#include <limits>
#include <cmath> // for isnan, isinf
#include <cstdlib> // for strtod
#include <iomanip> // for setprecision

// orthodox canonical section
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	// supressing warning
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	// supressing warning
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

// convert
void ScalarConverter::convert(const std::string &literal)
{
	try
	{
		// special cases

		// in subjects provided example:
		// ./convert nan
		// char: impossible
		// int: impossible
		// float: nanf
		// double: nan
		if (isPseudoLiteral(literal))
		{
			if (literal == "nan" || literal == "nanf")
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			}
			else if (literal == "+inf" || literal == "+inff")
			{
				std::cout << "char: impossible" << std::endl; 
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
			}
			else if (literal == "-inf" || literal == "-inff")
			{
				std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
			}
			return;
		}

		// converting string to double for a base conversion
		// strtod: Convert a string to a floating-point number.
		char *end;
		double value = std::strtod(literal.c_str(), &end);

		// for invalid literal
		// also checking for 'f' in case of float literal
		if (*end != '\0' && *end != 'f') 
		{
			// TODO better error
			throw ScalarConverter::LiteralInWrongFormat();
		}

		// convertions
		convertToChar(value);
		convertToInt(value);
		convertToFloat(value);
		convertToDouble(value);
	}
	// maybe do more with this
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// conversion functions for each data type
void ScalarConverter::convertToChar(double value)
{
	// checking limits
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value))
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (std::isprint(static_cast<int>(value)))
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non Displayable" << std::endl;
	}
}

void ScalarConverter::convertToInt(double value)
{
	// checking limits
	if(value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}


// std::setprecision(1) with std::fixed controls the number of digits after the decimal point
// without std::fixed, it controls the total number of significant digits
void ScalarConverter::convertToFloat(double value)
{
	if(std::isnan(value) || std::isinf(value))
	{
		std::cout << "float: " << value << "f" << std::endl;
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::convertToDouble(double value)
{
	if(std::isnan(value) || std::isinf(value))
	{
		std::cout << "double: " << value << std::endl;
	}
	else
	{
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" ||
            literal == "+inff" || literal == "-inff");
}

// Exceptions
// TODO maybe provide right format
const char *ScalarConverter::LiteralInWrongFormat::what() const throw()
{
	return "Literal is in wrong format";
}