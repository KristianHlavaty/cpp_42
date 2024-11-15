#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
		// orthodox canonical form
		MutantStack() : std::stack<T>(){}
		MutantStack(const MutantStack &other) : std::stack<T>(other){}
		MutantStack &operator=(const MutantStack &other)
		{
			if(this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack(){}
};
#endif