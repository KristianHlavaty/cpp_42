#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> stack;

	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		bool isValidInput(const std::string &input);
		bool isOperator(const std::string &oprator) const;
		bool isNumber(const std::string &number) const;
};
#endif