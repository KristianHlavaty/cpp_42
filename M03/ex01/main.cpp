#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");

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