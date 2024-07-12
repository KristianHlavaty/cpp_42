#include <iostream>
#include <string>

int main (void)
{
	// String variable initialized
	std::string brain = "HI THIS IS BRAIN";

	// Pointer to string variable
	std::string* stringPTR = &brain;

	// Reference to string variable
	std::string& stringREF = brain;

	// Printing memory addresses
	std::cout << "Memory address of the string variable: " << &brain << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	// Printing values
	std::cout << "Value of the string variable: " << brain << std::endl;
	std::cout << "Value held by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value held by stringREF: " << stringREF << std::endl;

	return 0;
}