#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // Test individual animals
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    // Create an array of animals
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    // Test deep copy
    Dog dog1;
    Dog dog2 = dog1; // Calls copy constructor
    Dog dog3;
    dog3 = dog1; // Calls copy assignment operator

    Cat cat1;
    Cat cat2 = cat1; // Calls copy constructor
    Cat cat3;
    cat3 = cat1; // Calls copy assignment operator

	// Check if ideas are copied correctly
    dog1.printIdea(47);
    dog2.printIdea(47);
    dog3.printIdea(47);

    cat1.printIdea(47);
    cat2.printIdea(47);
    cat3.printIdea(47);
	
    // Clean up
    for (int i = 0; i < 4; ++i)
	{
        delete animals[i];
    }

    return 0;
}