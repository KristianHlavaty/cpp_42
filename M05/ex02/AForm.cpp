#include "AForm.hpp"

// Default constructor
AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	// std::cout << "AForm default constructor called" << std::endl;
}

// Constructor with parameters
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm constructor with parameters called" << std::endl;
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
AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	// std::cout << "AForm copy constructor called" << std::endl;
}
// Copy assignment operator
AForm &AForm::operator=(const AForm &other)
{
	// std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl;
}

// Getters
std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	// "Aform status to signed if the bureaucrat’s
	// grade is high enough (higher or egal to the required one)"
	// 150 is lowest and 1 is highest possible grade
	if (b.getGrade() > _gradeToSign)
	{
        throw GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::beExecutable(const Bureaucrat &b, const AForm &f)
{
	if(b.getGrade() > _gradeToSign)
	{
		throw GradeTooLowToSignException();
	}
	if(f.getGradeToExecute() > _gradeToExecute)
	{
		throw GradeTooLowToExecuteException();
	}
}

// Exception
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::GradeTooLowToSignException::what() const throw()
{
	return "Grade is too low to sign the form!";
}

const char *AForm::GradeTooLowToExecuteException::what() const throw()
{
	return "Grade is too low to execute the form!";
}

// overload << operator
// for custom output
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm " << f.getName()
        << ", signing grade: " << f.getGradeToSign()
        << ", execution grade: " << f.getGradeToExecute()
        << ", is signed: " << (f.getIsSigned() ? "True" : "False");
	return out;
}
