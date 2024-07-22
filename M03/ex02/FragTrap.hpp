#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const std::string& name);
		~FragTrap();

		std::string getClassName() const;

		void highFivesGuys(void);
		void attack(const std::string& target);
};

#endif