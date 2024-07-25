#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog type";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
	_type = other._type;
	std::cout << _type << " has been copied! (copy constructor)" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if(this != &other)
	{
		_type = other._type;
	}
	std::cout << _type << "has been assigned! (copy assignment operator)" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << _type << " has been destroyed! (destructor)" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
