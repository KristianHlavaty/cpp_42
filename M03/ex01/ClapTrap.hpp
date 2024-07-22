#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string.h>
#include <iostream>

class ClapTrap
{
// Private members of a class are only accessible within that class.
// Protected members are accessible within the class and by derived classes. <- thats why I changed it
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		void printStatus() const;

	public:
		ClapTrap(const std::string& name);
		virtual ~ClapTrap(); // because i added polymorphic behaviour, I need to add virtual for proper cleanup

		virtual std::string getClassName() const; // virtual because i need class name

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
