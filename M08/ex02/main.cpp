#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "subject tests" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	// list
	std::cout << std::endl;
	std::cout << "list for comparision" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;
	lst.pop_back();

	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	// some other tests
	// copy constructor and assignment op.
	std::cout << std::endl;
	std::cout << "copy constructor" << std::endl;
	MutantStack<int> copyStack(mstack);
	std::cout << "Copy stack top: " << copyStack.top() << std::endl;
	copyStack.pop();
	std::cout << "After pop, original stack size: " << mstack.size() << ", copy stack size: " << copyStack.size() << std::endl;

	std::cout << std::endl;
	std::cout << "assignment operator" << std::endl;
	MutantStack<int> assignStack;
	assignStack = mstack;
	std::cout << "Assing stack top: " << assignStack.top() << std::endl;
	
	std::cout << std::endl;
	std::cout << "string" << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Deutsche");
	stringStack.push("Bank");
	MutantStack<std::string>::iterator strIt = stringStack.begin();
	MutantStack<std::string>::iterator strIte = stringStack.end();
	while (strIt != strIte)
	{
		std::cout << *strIt << std::endl;
		++strIt;
	}
	return 0;
}