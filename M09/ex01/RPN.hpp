#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> stack;

	public:
		RPN();
		~RPN();
		RPN(const RPN &);
		RPN &operator=(const RPN &);

		bool validateAndPerform(const std::string &input, int &result);
		bool isOperator(const std::string &oprator) const;
		bool isNumber(const std::string &number) const;
		int	performOperation(const std::string &oprator, int a, int b) const;
};
#endif