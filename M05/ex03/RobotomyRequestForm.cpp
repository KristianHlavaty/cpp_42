#include "RobotomyRequestForm.hpp"
#include <cstdlib> // for rand()
#include <iostream>
#include <time.h> // srand() need for the rand to be actually random

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Creation Form", 72, 45), _target("Default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy creation", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
} 

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	beExecutable(executor, *this);
	std::cout << "some drilling noises" << std::endl;
	srand(time(0));
	int randomNumber = rand();
	if (randomNumber % 2 == 0)
	{
		std::cout << _target << " has been robotomized" << std::endl;
	}
	else
	{
		std::cerr << "Robotomy has failed" << std::endl;
		return;
	}
	
}