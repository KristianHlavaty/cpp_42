#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << getClassName() << " " << _name << " has been created! (child constructor)" << std::endl;
	printStatus();
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap " << _name << " has been copied! (copy constructor)" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ScavTrap " << _name << " has been assigned! (copy assignment operator)" << std::endl;
    return *this;
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

void ScavTrap::attack(const std::string& target)
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
