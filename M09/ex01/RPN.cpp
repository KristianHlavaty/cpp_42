#include "RPN.hpp"

RPN::RPN()
{

}
RPN::~RPN()
{

}
RPN::RPN(const RPN &)
{

}
RPN &RPN::operator=(const RPN &)
{
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

int RPN::performOperation(const std::string &oprator, int a, int b) const
{
	if(oprator == "+")
		return a + b;
	if(oprator == "-")
		return a - b;
	if(oprator == "*")
		return a * b;
	if(oprator == "/")
	{
		if(b == 0)
		{
			throw std::runtime_error("Error: You tried dividing by zero.");
		}
		return a / b;
	
	}
	throw std::runtime_error("Error: It seems likely that your operator kind of does not exist '" + oprator + "'.");
}

bool RPN::validateAndPerform(const std::string &input, int &result)
{
	std::istringstream iss(input);
	std::string renameme;
	std::stack<int> tempStack;

	while(iss >> renameme)
	{
		if(isNumber(renameme))
		{
			int number = std::atoi(renameme.c_str());
			tempStack.push(number);
		}
		else if(isOperator(renameme))
		{
			if(tempStack.size() < 2)
			{
				std::cerr << "Error: Not enough operands for operator '" << renameme << "'." << std::endl;
				return false;
			}
			int b = tempStack.top();
			tempStack.pop();
			int a = tempStack.top();
			tempStack.pop();
			try 
			{
				int operationResult = performOperation(renameme, a, b);
				tempStack.push(operationResult);
			} 
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
				return false;
			}
		}
		else
		{
			std::cerr << "Error: Invalid input '" << renameme << "'." << std::endl;
			return false;
		}
	}
	// if the expression is valid, size should be just one
	// because all thats left is a final result
	if(tempStack.size() != 1)
	{
		std::cerr << "Error: Invalid RPN expression. Remaining stack size: " << tempStack.size() << "." << std::endl;
		return false;
	}
	result = tempStack.top();
	return true;
}