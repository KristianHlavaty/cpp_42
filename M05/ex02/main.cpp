#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat b0;
	std::cout << b0 << std::endl; // Should output: "Default Bureaucrat, bureaucrat grade 150"

	Bureaucrat highRank("HighRank", 1);
	Bureaucrat lowRank("LowRank", 150);

	ShrubberyCreationForm shrubberyForm("home");
	RobotomyRequestForm robotomyRequestForm("home?");

	// the whole signForm and executeForm inside is in try catch, so it is redundant to 
	// do it here, just if anybody is wondering
	lowRank.signForm(shrubberyForm); // should fail
	highRank.signForm(shrubberyForm); // should succeed
	lowRank.executeForm(shrubberyForm); // should fail
	highRank.executeForm(shrubberyForm); // should succeed

	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	
	lowRank.signForm(robotomyRequestForm); // should fail
	highRank.signForm(robotomyRequestForm); // should succeed
	lowRank.executeForm(robotomyRequestForm); // should fail
	highRank.executeForm(robotomyRequestForm); // should succeed
	return 0;
}

// test for the Shrubbery for lazy people
// make && ./Bureaucrat && cat home_shrubbery && rm home_shrubbery && make fclean