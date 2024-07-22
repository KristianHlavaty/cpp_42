#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");

	clap.initialize();
	clap.attack("target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.beRepaired(5);

	ScavTrap scav("SC4V-TP");
	scav.attack("target2");
	scav.takeDamage(20);
	scav.beRepaired(15);
	scav.guardGate();

	return 0;
}

// The destructor for ScavTrap is called first because
// the derived class's destructor is called before the base class's destructor.

// The destructor for ClapTrap will still show "ClapTrap" because when a derived
// class object is destroyed, the base class destructor doesn't use polymorphism
// to call the overridden method. This is a limitation in C++

// 3 messages for destructor are because of how virtual destructors and polymorphism work in C++
// Each class's destructor gets called in the chain, and the virtual destructor in ClapTrap
// ensures the derived class destructor (ScavTrap) is also called.

// When the ScavTrap destructor is called, it automatically calls the ClapTrap destructor,
// resulting in a double message because the ScavTrap destructor is explicitly printing
// the destruction message also.