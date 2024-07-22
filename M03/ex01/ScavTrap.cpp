#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << getClassName() << " " << _name << " has been created! (child constructor)" << std::endl;
	printStatus();
}

ScavTrap::~ScavTrap()
{
	std::cout << getClassName() << " " << _name << " has been destroyed! (destructor)" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << getClassName() << " " << _name << " is now in Gate keeper mode!" << std::endl;
}

std::string ScavTrap::getClassName() const
{
	return "ScavTrap";
}
