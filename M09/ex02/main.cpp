#include "PmergeMe.hpp"

#include <ctime>
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe integers" <<std::endl;
		return 1;
	}
	try 
	{
		PmergeMe pmergeMe; 
		
		clock_t start, end;
		
		start = clock();
		pmergeMe.mergeInsertVector(ac, av);
		end = clock();
		const std::vector<int> &finalVec = pmergeMe.getSortedVector();
		printContainer(finalVec, "After: ");
		std::cout << "\nTime to sort with vector: " << static_cast<double>(end - start) * 1000000/ CLOCKS_PER_SEC << " us\n";
		start = clock();
		pmergeMe.mergeInsertDeque(ac, av);
		end = clock();
		// check for deque if the numbers are also in right order
		const std::deque<int> &finalDeq = pmergeMe.getSortedDeque();
		printContainer(finalDeq, "After: ");
		std::cout << "Time to sort with deque: " << static_cast<double>(end - start) * 1000000/ CLOCKS_PER_SEC << " us\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

//  ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`