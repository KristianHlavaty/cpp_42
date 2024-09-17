#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl; // just for testing everywhere
}

// Constructor with parameters
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor with parameters called" << std::endl;
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout<< "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// _name is const so no copying
		_grade = other._grade;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout<< "Bureaucrat dectructor called" << std::endl;
}

// Getters
std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// incre/decrement grade
// 150 is lowest and 1 is highest possible grade
void Bureaucrat::incrementGrade()
{
	if(_grade <= 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
	std::cout << "bur grade increment" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if(_grade >= 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
	std::cout << "bur grade decrement" << std::endl;
}

// Exception
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// overload << operator
// for custom output format: "name, bureaucrat grade grade"
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}