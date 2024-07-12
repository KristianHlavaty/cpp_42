#include "Zombie.hpp"

// constructor
Zombie::Zombie(std::string name) : _name(name){}

// member function
void Zombie::announce(void)
{
	std::cout << _name << ": Braiiiiiiinnnssss..." << std::endl;
}

// destructor
Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}