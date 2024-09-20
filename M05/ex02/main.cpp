#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b0;
	std::cout << b0 << std::endl; // Should output: "Default Bureaucrat, bureaucrat grade 150"

	Bureaucrat highRank("HighRank", 1);
	Bureaucrat lowRank("LowRank", 150);

	ShrubberyCreationForm shrubberyForm("home");
	
	lowRank.signForm(shrubberyForm); // should fail
	highRank.signForm(shrubberyForm); // should succeed
	lowRank.executeForm(shrubberyForm); // should fail
	highRank.executeForm(shrubberyForm); // should succeed
	return 0;
}

// test for the Shrubbery for lazy people
// make && ./Bureaucrat && cat home_shrubbery && rm home_shrubbery && make fclean