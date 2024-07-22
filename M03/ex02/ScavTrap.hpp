#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string& name);
		~ScavTrap();
		ScavTrap(const ScavTrap& other); // Copy constructor
    	ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator

		std::string getClassName() const; // need to return "ScavTrap"

		void guardGate();
		void attack(const std::string& target);
};

#endif