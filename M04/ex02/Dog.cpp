#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
   	_brain = new Brain(*other._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
	{
        Animal::operator=(other);
		*_brain = *other._brain;
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << _type << " has been destroyed! (destructor)" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

// added for testing
void Dog::printIdea(int index) const
{
    std::cout << "Dog idea " << index << ": " << _brain->getIdea(index) << std::endl;
}
