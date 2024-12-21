#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <set>

class PmergeMe
{
	private:
		std::vector<int> generateJacobsthalNumbers(size_t size);

		template <typename Container>
		void pairAndSort(Container &sequence, Container &main, Container &pend);

		template <typename Container>
		void recursivePairSort(Container &sequence, size_t step);

		template <typename Container>
		void insertPendElements(Container &main, Container &pend);

		

	public:
		PmergeMe();
		~PmergeMe();

		void fordJohnsonSortVector(std::vector<int> &sequence);
		void fordJohnsonSortDeque(std::deque<int> &sequence);
		void measureTimeAndSort(int ac, char **av);
		static bool validateInput(char **input, int size);
};

// templates so i dont have to write it twice for deque
template <typename Container>
void PmergeMe::recursivePairSort(Container& sequence, size_t step)
{
	if (sequence.size() < 2 * step)
		return;

	for (size_t i = 0; i + 2 * step - 1 < sequence.size(); i += 2 * step)
	{
		if (sequence[i + step] > sequence[i + 2 * step - 1])
		{
			for (size_t j = 0; j < step; ++j)
				std::swap(sequence[i + j], sequence[i + step + j]);
		}
	}
	recursivePairSort(sequence, step * 2);
}

// Splits "sequence" into "main" (larger) and "pend" (smaller)
template <typename Container>
void PmergeMe::pairAndSort(Container& sequence, Container& main, Container& pend)
{
	for (size_t i = 0; i + 1 < sequence.size(); i += 2)
	{
		if (sequence[i] > sequence[i + 1])
		{
			// Swapping to ensure sequence[i] is "b" and sequence[i + 1] is "a"
			std::swap(sequence[i], sequence[i + 1]);
		}
		// smaller element
		main.push_back(sequence[i + 1]);
		// larget element
		pend.push_back(sequence[i]);
	}
	// unpaired element
	if (sequence.size() % 2 != 0)
		pend.push_back(sequence.back());

	// sorting the larger elements (main) recursively
	recursivePairSort(main, 1);

	std::cout << "Main after pairAndSort: ";
	for (size_t i = 0; i < main.size(); ++i)
		std::cout << main[i] << " ";
	std::cout << std::endl;

	std::cout << "Pend after pairAndSort: ";
	for (size_t i = 0; i < pend.size(); ++i)
		std::cout << pend[i] << " ";
	std::cout << std::endl;
}

// Inserts elements from "pend" into "main" using Jacobsthal order
template <typename Container>
void PmergeMe::insertPendElements(Container& main, Container& pend)
{
	std::vector<int> jacobsthal = generateJacobsthalNumbers(pend.size());
	std::set<size_t> processedIndices;

	std::cout << "Pend before insertion: ";
	for (size_t i = 0; i < pend.size(); ++i)
		std::cout << pend[i] << " ";
	std::cout << std::endl;
	// Insert elements from pend into main based on Jacobsthal sequence
	for (size_t i = 0; i < jacobsthal.size(); ++i)
	{
		size_t index = jacobsthal[i] - 1;
		if (index < pend.size() && processedIndices.find(index) == processedIndices.end())
		{
			typename Container::iterator pos = main.begin();

			// Manual binary search for insertion position
			while (pos != main.end() && *pos < pend[index])
				++pos;

			main.insert(pos, pend[index]);
			processedIndices.insert(index);
		}
	}

	// Insert remaining elements from pend that were not covered by Jacobsthal
	for (size_t i = 0; i < pend.size(); ++i)
	{
		if (processedIndices.find(i) == processedIndices.end())
		{
			typename Container::iterator pos = main.begin();

			// Manual binary search for insertion position
			while (pos != main.end() && *pos < pend[i])
				++pos;

			main.insert(pos, pend[i]);
		}
	}
	std::cout << "Main after insertion: ";
	for (typename Container::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif
