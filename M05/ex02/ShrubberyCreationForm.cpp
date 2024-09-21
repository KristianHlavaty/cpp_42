#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 147, 137), _target("Default Target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// "You have to check that the form is signed and that the grade of the bureaucrat
	// attempting to execute the form is high enough" - from subject
	beExecutable(executor, *this);
	// does not have a constructor that takes a std::string directly
	// fixed by using .c_str
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if(!ofs)
	{
		std::cerr << "Error: Could not create file " << _target + "_shrubbery" << std::endl;
		return;
	}
ofs << "                            \n"
		"       _-_               _-_\n"
        "    /~~   ~~\\         /~~   ~~\\\n"
        " /~~         ~~\\    /~~       ~~\\\n"
        "{               }  {             }\n"
        " \\  _-     -_  /    \\ _-     -_ /\n"
        "   ~  \\\\ //  ~     ~    \\\\ //  ~\n"
        "_- -   | | _- _  _- -    | | _- _\n"
        "  _ -  | |   -_    _ -   | |   -_\n"
        "      // \\\\             // \\\\\n";
	ofs.close();
}
