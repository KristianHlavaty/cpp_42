#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		~Zombie(); // destructor for the Zombie class
		void announce(void);
};

void 	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
