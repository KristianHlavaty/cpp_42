#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		std::ostringstream oss;
		oss << "Default idea " << i;
		ideas[i] = oss.str();
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	if(this != &other)
	{
		std::cout << "Brain copy assignment operator called" << std::endl;
		for (int i = 0; i < 100; ++i)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// added for testing
std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return ideas[index];
	}
	return "not valid index";
}