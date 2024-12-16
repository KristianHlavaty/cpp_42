#include "RPN.hpp"

RPN::RPN()
{

}
RPN::~RPN()
{

}
RPN::RPN(const RPN &other)
{
	(void)other;
}
RPN &RPN::operator=(const RPN &other)
{
	if(this != &other)
	{

	}
	return *this;
}

// operator is a keyword, thats why this name :D
bool RPN::isOperator(const std::string &oprator) const
{
	return oprator == "+" || oprator == "-" || oprator == "*" || oprator == "/";
}
bool RPN::isNumber(const std::string &number) const
{
	return number.size() == 1 && std::isdigit(number[0]);
}

bool RPN::isValidInput(const std::string &input)
{
	std::istringstream iss(input);
	std::string renameme;
	std::stack<int> tempStack;

	while(iss >> renameme)
	{
		if(isNumber(renameme))
		{
			int number;
			std::istringstream iss(renameme);
			iss >> number;
			tempStack.push(number);
		}
		else if(isOperator(renameme))
		{
			if(tempStack.size() < 2)
			{
				std::cerr << "Error: Not enough operands for operator '" << renameme << "'." << std::endl;
			}
			// poping two operands
			tempStack.pop();
			tempStack.pop();
			// just a placeholder value as a result
			tempStack.push(1);
		}
		else
		{
			std::cerr << "Error: Invalid input '" << renameme << "'." << std::endl;
			return false;
		}
	}
	if(tempStack.size() != 1)
	{
		std::cerr << "Error: Invalid RPN expression. Remaining stack size: " << stack.size() << "." << std::endl;
	}

	return true;
}