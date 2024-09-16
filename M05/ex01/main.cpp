#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b0;
	std::cout << b0 << std::endl; // Should output: "Default Bureaucrat, bureaucrat grade 150"

	try
	{
		Bureaucrat b1("Testunson", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;
		
		b1.incrementGrade(); // should throw exception
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Evil twin of Testunson", 149);
		std::cout << b2 << std::endl;

		b2.decrementGrade();
		std::cout << b2 << std::endl;

		b2.decrementGrade(); // should throw exception
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}
	return 0;
}