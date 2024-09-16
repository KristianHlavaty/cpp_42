#include "Form.hpp"

// Default constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

