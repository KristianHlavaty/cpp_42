#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << getClassName() << " " << _name << " has been created! (child constructor)" << std::endl;
	printStatus();
}

FragTrap::~FragTrap()
{
	std::cout  << getClassName() << " " << _name << " has been destroyed! (destructor)" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << getClassName() << " " << _name << " requests a positive high five!" << std::endl;
}

std::string FragTrap::getClassName() const
{
	return "FragTrap";
}

void FragTrap::attack(const std::string& target)
{
	if(_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << getClassName() << " " << _name << " has no hit points or energy points left to attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << getClassName() << " " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	printStatus();
}
