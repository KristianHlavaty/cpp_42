#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::announce() const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}