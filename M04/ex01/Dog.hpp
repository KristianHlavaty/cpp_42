#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog& other); // copy constructor
		Dog& operator=(const Dog& other); // copy assignment operator

		void makeSound() const;
		void printIdea(int index) const; // added for testing
};

#endif