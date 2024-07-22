#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), 
	FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " has been created! (constructor)" << std::endl;
    printStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other._name + "_clap_name"), FragTrap(other._name + "_clap_name"), ScavTrap(other._name + "_clap_name"), _name(other._name)
{
    *this = other;
    std::cout << "DiamondTrap " << _name << " has been copied! (copy constructor)" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap " << _name << " has been assigned! (copy assignment operator)" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " has been destroyed! (destructor)" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target); // Use ScavTrap's attack
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getClassName() const
{
    return "DiamondTrap";
}