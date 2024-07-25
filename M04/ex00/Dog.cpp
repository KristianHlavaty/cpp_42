#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog type";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
	{
        Animal::operator=(other);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
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
