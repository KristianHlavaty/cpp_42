#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);

		virtual void makeSound() const = 0; // pure virtual function
		std::string getType() const;

};
#endif

// To make the class abstract, we need to ensure that it cannot be 
// instantiated directly (creating an object of a class using its constructor).
// This can be achieved by declaring at least one pure virtual function in the class.

// i already have virtual function makeSound by assingning it to 0 i make it pure virtual function