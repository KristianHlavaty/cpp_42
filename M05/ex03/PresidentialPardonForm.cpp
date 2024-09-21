#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Creation Form", 25, 5), _target("Default Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Creation", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		// _target is std::string
		// std::string handles its own memory management and copying, no * needed
		_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	beExecutable(executor, *this);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}