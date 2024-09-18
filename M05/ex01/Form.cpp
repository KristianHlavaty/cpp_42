#include "Form.hpp"

// Default constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	// std::cout << "Form default constructor called" << std::endl;
}

// Constructor with parameters
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "Form constructor with parameters called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw GradeTooLowException();
	}
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	// std::cout << "Form copy constructor called" << std::endl;
}
// Copy assignment operator
Form &Form::operator=(const Form &other)
{
	// std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
Form::~Form()
{
	// std::cout << "Form destructor called" << std::endl;
}

// Getters
std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
	// "form status to signed if the bureaucrat’s
	// grade is high enough (higher or egal to the required one)"
	// 150 is lowest and 1 is highest possible grade
	if (b.getGrade() > _gradeToSign)
	{
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// Exception
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// overload << operator
// for custom output
std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form " << f.getName()
        << ", signing grade: " << f.getGradeToSign()
        << ", execution grade: " << f.getGradeToExecute()
        << ", is signed: " << (f.getIsSigned() ? "True" : "False");
	return out;
}
