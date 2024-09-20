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
	try
	{
		Bureaucrat emil("Emil", 50);
		// FOLLOWING TEST SHOULD NOT COMPILE
		// name, grade to sign, grade to execute
		// AForm taxForm("Tax Form", 46, 20);

		// std::cout << taxForm << std::endl;

		// try to sign the form
		// emil.signForm(taxForm);

		// std::cout << taxForm << std::endl;

		// Bureaucrat blabla("Blabla", 40);
		// blabla.signForm(taxForm);

		// std::cout << taxForm << std::endl;

		// Bureaucrat blablanson("Blablanson", 40);
		// blablanson.signForm(taxForm);

		// std::cout << taxForm << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	// should fail
    try
    {
        lowRank.signForm(shrubberyForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // should succeed
    try
    {
        highRank.signForm(shrubberyForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << shrubberyForm << std::endl;

    // should fail
    try
    {
        lowRank.executeForm(shrubberyForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // should succeed
    try
    {
        highRank.executeForm(shrubberyForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	return 0;
}