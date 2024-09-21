#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <map>

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

// form creation
AForm* Intern::createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	typedef AForm* (*FormCreator)(const std::string &target);
	std::map<std::string, FormCreator> formCreators;

	formCreators.insert(std::make_pair("shrubbery creation", createShrubberyCreationForm));
	formCreators.insert(std::make_pair("robotomy request", createRobotomyRequestForm));
	formCreators.insert(std::make_pair("presidential pardon", createPresidentialPardonForm));

	std::map<std::string, FormCreator>::iterator it = formCreators.find(formName);
	if (it != formCreators.end())
	{
		std::cout << "Intern creates " << formName << std::endl;
		return it->second(target);
	}
	else
	{
		std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
		return NULL;
	}
}