#include "PmergeMe.hpp"

// Default Constructor and Destructor
PmergeMe::PmergeMe()
{

}
PmergeMe::~PmergeMe()
{

}

bool PmergeMe::validateInput(char **input, int size)
{
	for (int i = 1; i < size; ++i)
	{
		std::string arg(input[i]);
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(arg[j]))
			{
				std::cerr << "Error: Invalid input" << std::endl;
				return false;
			}
		}
	}
	return true;
}
// Generate Jacobsthal numbers
std::vector<int> PmergeMe::generateJacobsthalNumbers(size_t size)
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1); // J(1) = 1
	int n1 = 1, n2 = 3;      // J(2) = 3
	while (n2 <= static_cast<int>(size))
	{
		jacobsthal.push_back(n2);
		int temp = n2 + 2 * n1;
		n1 = n2;
		n2 = temp;
	}
	return jacobsthal;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& sequence)
{
	std::vector<int> main, pend;
	pairAndSort(sequence, main, pend);
	insertPendElements(main, pend);
	sequence = main;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& sequence)
{
	std::deque<int> main, pend;
	pairAndSort(sequence, main, pend);
	insertPendElements(main, pend);
	sequence = main;
}

// Measure time and sort
void PmergeMe::measureTimeAndSort(int ac, char **av)
{
	if (ac < 2 || !validateInput(av, ac))
	{
		std::cerr << "Error: Invalid input" << std::endl;
		return;
	}

	// Convert input into a vector of integers
	std::vector<int> input;
	for (int i = 1; i < ac; ++i)
	{
		input.push_back(std::atoi(av[i]));
	}
	
	std::vector<int> vec(input);
	std::deque<int> deq(input.begin(), input.end());

	clock_t start, end;

	std::cout << "Before: ";
	for (size_t i = 0; i < input.size(); ++i)
		std::cout << input[i] << " ";
	std::cout << std::endl;

	start = clock();
	fordJohnsonSortVector(vec);
	end = clock();
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\nTime to sort with vector: " << static_cast<double>(end - start) * 1000000/ CLOCKS_PER_SEC << " us\n";

	start = clock();
	fordJohnsonSortDeque(deq);
	end = clock();
	std::cout << "Time to sort with deque: " << static_cast<double>(end - start) * 1000000/ CLOCKS_PER_SEC << " us\n";
}
