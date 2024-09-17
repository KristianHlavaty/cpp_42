#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		Form(); // default constructor I put it there because Igor told me to xD
				// supposedly it should be for the compiler,
				// so we can't access it directly, but the compiler doesnt
				// create its own

	public:
		Form(const std::string &name, int gradeToSign, int gradeToExecute); // constructor
		Form(const Form &other); // copy constructor
		Form &operator=(const Form &other); // copy assignment operator
		~Form(); // destructor

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &b);

		// Exceptions
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
// for custom output format
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif