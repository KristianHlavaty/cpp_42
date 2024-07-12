#include "Zombie.hpp"

int main(void)
{
	// heap zombie
	// +
	// dynamic lifetime (can outlive the function), flexibility in size
	// -
	// manual memory management, slower allocation
	Zombie* heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	// stack zombie
	// +
	// automatic memory management, faster allocation
	// -
	// fixed size, limited lifetime (when the function returns)

	// main difference when to use it is scope and lifetime
	randomChump("stackZombie");
	return 0;
}