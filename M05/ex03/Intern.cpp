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

AForm* Intern::createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	// might not need to expose it in .hpp file, will keep it here for now
	struct FormEntry
	{
		std::string name;
		AForm* (*create)(const std::string &target);
	};

	FormEntry formEntries[] =
	{
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
        {"presidential pardon", createPresidentialPardonForm},
	};

	// should work if I add new entries
	for (size_t i = 0; i < sizeof(formEntries) / sizeof(FormEntry); ++i)
	{
		if (formEntries[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formEntries[i].create(target);
		}
	}

	std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}