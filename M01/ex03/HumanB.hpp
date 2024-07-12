#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

// pointer to allow optional assignment of a weapon
class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack() const;
};

#endif