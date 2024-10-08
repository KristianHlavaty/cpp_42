#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b0;
	std::cout << b0 << std::endl; // Should output: "Default Bureaucrat, bureaucrat grade 150"

	Bureaucrat emil("Emil", 50);
	// name, grade to sign, grade to execute
	// right now not executing, will probably have to implement it on the next one
	Form taxForm("Tax Form", 46, 20);

	std::cout << taxForm << std::endl;

	// try to sign the form
	emil.signForm(taxForm);

	std::cout << taxForm << std::endl;

	Bureaucrat blabla("Blabla", 40);
	blabla.signForm(taxForm);

	std::cout << taxForm << std::endl;

	Bureaucrat blablanson("Blablanson", 40);
	blablanson.signForm(taxForm);

	std::cout << taxForm << std::endl;
	return 0;
}