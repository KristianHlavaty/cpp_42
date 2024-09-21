#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm(); // Default constructor
			// we can't access it directly since its private
			// and I am doing it
			// so the compiler doesnt
			// create its own
	public:
		PresidentialPardonForm(const std::string &target); // constructor
		virtual ~PresidentialPardonForm(); // destructor
		PresidentialPardonForm(const PresidentialPardonForm &other); // copy constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other); // copy assignment operator

		void execute(Bureaucrat const &executor) const;
};

#endif