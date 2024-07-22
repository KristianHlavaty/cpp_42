#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");

	clap.attack("target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.beRepaired(5);

	clap.attack("target2");

	return 0;
}