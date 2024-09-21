#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// constructor + default constructor (the same)
Intern::Intern()
{
}

// Copy constructor
Intern::Intern(const Intern &other)
{
	// supressing warning
	(void)other;
}

// Copy assignment operator
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{

	}
	return *this;
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::cout << "test" << std::endl;
	(void)formName;
	(void)target;
	return 0;
}