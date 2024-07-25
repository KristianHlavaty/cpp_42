#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// Test instantiation of Animal (should not compile)
    // Animal myAnimal;  // Uncommenting this line should cause a compilation error
    // Animal* myAnimalPtr = new Animal();  // Uncommenting this line should cause a compilation error
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


// Abstract classes act as expressions of general concepts from which more
// specific classes can be derived. You can't create an object of an abstract
// class type. However, you can use pointers and references to abstract class types.

// You create an abstract class by declaring at least one pure virtual member function.
// That's a virtual function declared by using the pure specifier (= 0) syntax. Classes
// derived from the abstract class must implement the pure virtual function or they, too,
// are abstract classes.

// the way I understand the point of the exercise
// the point is to create a class (Animal) that is used in its
// derived classes Dog, Cat , but cannot be created directly thus it is abstract class