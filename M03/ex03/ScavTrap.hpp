#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// needed to add virtual because of the inheritance
class ScavTrap : virtual public ClapTrap
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