#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private: 
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(); // default constructor
		Bureaucrat(const std::string &name, int grade); // constructor
		Bureaucrat(const Bureaucrat &other); // copy constructor
		Bureaucrat &operator=(const Bureaucrat &other); // copy assignment operator
		~Bureaucrat(); // destructor

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &aForm);
		void executeForm(const AForm &form); // new in this ex
		
		// Exceptions
		// I am inheriting form the std::exception which has already virtual what() method
		// so it would be redundant to use it here
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// Overload the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif