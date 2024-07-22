#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	DiamondTrap diamond("DI4M-TP");
    diamond.attack("target4");
    diamond.takeDamage(30);
    diamond.beRepaired(10);
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();

	// std::cout << "Testing copy constructor and assignment operator:" << std::endl;

    // DiamondTrap copyDiamond(diamond); // Copy constructor
    // copyDiamond.whoAmI();

    // DiamondTrap assignedDiamond("TEMP-TP");
    // assignedDiamond = diamond; // Copy assignment operator
    // assignedDiamond.whoAmI();

	return 0;
}
