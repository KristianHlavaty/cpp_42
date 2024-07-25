#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "Testing WrongAnimal and WrongCat:" << std::endl;
    
    const WrongAnimal* metaWrong = new WrongAnimal();
    const WrongAnimal* iWrong = new WrongCat();

    std::cout << iWrong->getType() << " " << std::endl;

    iWrong->makeSound(); // will output the WrongAnimal sound!
    metaWrong->makeSound();

    delete metaWrong;
    delete iWrong;

	return 0;
}