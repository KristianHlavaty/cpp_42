#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& other); // copy constructor
		Dog& operator=(const Dog& other); // copy assignment operator

		void makeSound() const;
};

#endif