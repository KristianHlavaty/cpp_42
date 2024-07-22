#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap (child constructor)" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap " << _name << " has been copied! (copy constructor)" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other); // Call base class assignment operator
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "FragTrap " << _name << " has been assigned! (copy assignment operator)" << std::endl;
    return *this;
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

void FragTrap::initialize()
{
    std::cout << getClassName() << " " << _name << " has been created!" << std::endl;
    printStatus();
}