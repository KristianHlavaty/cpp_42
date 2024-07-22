#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap(const FragTrap& other); // Copy constructor
    	FragTrap& operator=(const FragTrap& other); // Copy assignment operator

		std::string getClassName() const;

		void highFivesGuys(void);
		void attack(const std::string& target);
		void initialize(); // now needed for diamond to not write wrong messages
};

#endif