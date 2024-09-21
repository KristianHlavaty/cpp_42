#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"


class Bureaucrat;
class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		AForm(); // default constructor I put it there because Igor told me to xD
				// supposedly it should be for the compiler,
				// so we can't access it directly, but the compiler doesnt
				// create its own

	public:
		AForm(const std::string &name, int gradeToSign, int gradeToExecute); // constructor
		AForm(const AForm &other); // copy constructor
		AForm &operator=(const AForm &other); // copy assignment operator
		virtual ~AForm(); // destructor - made it virtual since this has to be abstract class

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &b);
		void beExecutable(const Bureaucrat &b, const AForm &f) const;
		// abstract class cant be instantiated directly
		// achieved by setting this to 0
		virtual void execute(const Bureaucrat &executor) const = 0;
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

		class GradeTooLowToSignException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
		class GradeTooLowToExecuteException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormIsNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// Overload the insertion (<<) operator
// for custom output format
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif