#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm(); // default constructor
	public:
		RobotomyRequestForm(const std::string &target); // constructor
		virtual ~RobotomyRequestForm(); // destructor
		RobotomyRequestForm(const RobotomyRequestForm &other); // copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other); // copy assignment operator

		void execute(Bureaucrat const &executor) const;
};

#endif