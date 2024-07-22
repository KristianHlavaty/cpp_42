#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	FragTrap frag("FR4G-TP");
	frag.attack("target3");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();

	return 0;
}
