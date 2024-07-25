#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal " << _type << " has been copied! (copy constructor)" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if(this != &other)
	{
		_type = other._type;
	}
	std::cout << "Animal " << _type << " has been assigned! (copy assignment operator)" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " has been destroyed! (destructor)" << std::endl;
}

// void Animal::makeSound() const
// {
// 	std::cout << "default Animal sound" << std::endl;
// }

std::string Animal::getType() const
{
	return _type;
}