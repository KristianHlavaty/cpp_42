#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

// ~Weapon(); in this case not needed
class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		const std::string &getType() const;
		void setType(std::string type);
};

#endif