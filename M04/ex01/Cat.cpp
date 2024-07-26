#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    _brain = new Brain(*other._brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
	{
        Animal::operator=(other);
		*_brain = *other._brain;
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << _type << " has been destroyed! (destructor)" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

// added for testing
void Cat::printIdea(int index) const
{
    std::cout << "Cat idea " << index << ": " << _brain->getIdea(index) << std::endl;
}