#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe sorter;
	sorter.measureTimeAndSort(ac, av);
	return 0;
}

//  ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`