#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat type";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_type = other._type;
	std::cout << _type << " has been copied! (copy constructor)" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if(this != &other)
	{
		_type = other._type;
	}
	std::cout << _type << "has been assigned! (copy assignment operator)" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << _type << " has been destroyed! (destructor)" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
