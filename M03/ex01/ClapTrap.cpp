#include "ClapTrap.hpp"

void ClapTrap::printStatus() const
{
	std::cout << getClassName() << " " << _name << " has " << _hitPoints << " hit points and " << _energyPoints << " energy points left." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << getClassName() << " " << _name << " has been created! (constructor)" << std::endl;
	printStatus();
}

ClapTrap::~ClapTrap()
{
	std::cout << getClassName() << " " << _name << " has been destroyed! (destructor)" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints == 0)
	{
		std::cout << getClassName() << " " << _name << " is already destroyed!" << std::endl;
		return;
	}
	_hitPoints = (amount >= _hitPoints) ? 0 : _hitPoints - amount;
	std::cout << getClassName() << " " << _name << " takes " << amount << " points of damage!" << std::endl;
	if(_hitPoints == 0)
	{
		std::cout << getClassName() << " " << _name << " has been destroyed by taking damage!" << std::endl;
	}
	printStatus();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << getClassName() << " " << _name << " has no hit points or energy points left to repair!" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << getClassName() << " " << _name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
	printStatus();
}

// i need this for ScavTrap otherwise i could just put everywhere the string
std::string ClapTrap::getClassName() const
{
	return "ClapTrap";
}
