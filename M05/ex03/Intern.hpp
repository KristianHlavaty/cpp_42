#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{	
	public:
		Intern(); // constructor - no need for the default, since
				  // 			   it is the same
		~Intern(); // destructor
		Intern(const Intern &other); // copy constructor
		Intern &operator=(const Intern &other); // copy assignment operator

		AForm* makeForm(const std::string &formName, const std::string &target);
};

#endif