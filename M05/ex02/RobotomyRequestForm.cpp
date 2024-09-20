#include "RobotomyRequestForm.hpp"

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
	std::cout << "test" << std::endl;

	// todo logic
}