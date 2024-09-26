#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n" << std::endl;
	std::cout << "DEFAULT TEST\n" << std::endl;
	Bureaucrat b0;
	std::cout << b0 << std::endl; // Should output: "Default Bureaucrat, bureaucrat grade 150"

	Bureaucrat highRank("HighRank", 1);
	Bureaucrat lowRank("LowRank", 150);

	ShrubberyCreationForm shrubberyForm("home");
	RobotomyRequestForm robotomyRequestForm("Pepa");
	PresidentialPardonForm presidentialPardonForm("King Kong");

	// the whole signForm and executeForm inside is in try catch, so it is redundant to 
	// do it here, just if anybody is wondering
	std::cout << "\n" << std::endl;
	std::cout << "SHRUBBERY SECTION\n" << std::endl;
	lowRank.signForm(shrubberyForm); // should fail
	highRank.signForm(shrubberyForm); // should succeed
	lowRank.executeForm(shrubberyForm); // should fail
	highRank.executeForm(shrubberyForm); // should succeed

	std::cout << "\n" << std::endl;
	std::cout << "ROBOTOMY SECTION\n" << std::endl;
	
	lowRank.signForm(robotomyRequestForm); // should fail
	highRank.signForm(robotomyRequestForm); // should succeed
	lowRank.executeForm(robotomyRequestForm); // should fail
	highRank.executeForm(robotomyRequestForm); // should succeed 50% of the time
	
	std::cout << "\n" << std::endl;
	std::cout << "PRESIDENTIAL SECTION\n" << std::endl;

	highRank.executeForm(presidentialPardonForm); // should throw not signed form error
	lowRank.signForm(presidentialPardonForm); // should fail
	highRank.signForm(presidentialPardonForm); // should succeed
	lowRank.executeForm(presidentialPardonForm); // should fail
	highRank.executeForm(presidentialPardonForm); // should succeed

	std::cout << "\n" << std::endl;
	std::cout << "INTERN SECTION\n" << std::endl;
	// initial test
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		lowRank.signForm(*rrf);
		highRank.signForm(*rrf);
		lowRank.executeForm(*rrf);
		highRank.executeForm(*rrf);
		delete rrf; // Free
	}
	std::cout << "\n" << std::endl;
	AForm* srf = someRandomIntern.makeForm("shrubbery creation", "Root");
	if (srf)
	{
		lowRank.signForm(*srf);
		highRank.signForm(*srf);
		lowRank.executeForm(*srf);
		highRank.executeForm(*srf);
		delete srf; // Free
	}
	std::cout << "\n" << std::endl;
	AForm* prf = someRandomIntern.makeForm("presidential pardon", "Frog");
	if (prf)
	{
		lowRank.signForm(*prf);
		highRank.signForm(*prf);
		lowRank.executeForm(*prf);
		highRank.executeForm(*prf);
		delete prf; // Free
	}

	return 0;
}

// test for the Shrubbery for lazy people
// make && ./Bureaucrat && cat home_shrubbery && rm home_shrubbery && make fclean