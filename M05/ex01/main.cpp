#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b0;
	std::cout << b0 << std::endl; // Should output: "Default Bureaucrat, bureaucrat grade 150"

	try
	{
		Bureaucrat emil("Emil", 50);
		Form taxForm("Tax Form", 75, 45);

		std::cout << taxForm << std::endl;

		// try to sign the form
		emil.signForm(taxForm);

		Bureaucrat blabla("Blabla", 40);
		blabla.signForm(taxForm);

		std::cout << taxForm << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}