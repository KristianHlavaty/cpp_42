#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat& other); // copy constructor
		Cat& operator=(const Cat& other); // copy assignment operator

		void makeSound() const;
		void printIdea(int index) const; // added for testing
};

#endif