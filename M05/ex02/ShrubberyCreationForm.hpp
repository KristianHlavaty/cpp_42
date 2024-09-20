#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm(); // default constructor I put it there because Igor told me to xD
				// supposedly it should be for the compiler,
				// so we can't access it directly, but the compiler doesnt
				// create its own
	public:
		ShrubberyCreationForm(const std::string &target); // constructor
		virtual ~ShrubberyCreationForm(); // destructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other); // copy constructor
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other); // copy assignment operator

		void execute(Bureaucrat const &executor) const;
};

#endif