#ifndef DIAMONDTRAP_HPP
#define DIAMONTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;
	public: 
		DiamondTrap(const std::string& name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& other); // Copy constructor
		
    	DiamondTrap& operator=(const DiamondTrap& other); // Copy assignment operator

		void attack(const std::string& target);
		void whoAmI();
		std::string getClassName() const;
};
#endif