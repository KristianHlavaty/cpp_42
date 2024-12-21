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
}

// Inserts elements from "pend" into "main" using Jacobsthal order
template <typename Container>
void PmergeMe::insertPendElements(Container& main, Container& pend)
{
	std::vector<int> jacobsthal = generateJacobsthalNumbers(pend.size());
	size_t inserted = 0;

	for (size_t i = 0; i < jacobsthal.size() && inserted < pend.size(); ++i)
	{
		size_t count = std::min<size_t>(jacobsthal[i] - (i > 0 ? jacobsthal[i - 1] : 0), pend.size() - inserted);
		for (size_t j = 0; j < count; ++j)
		{
			typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), pend[inserted]);
			main.insert(pos, pend[inserted]);
			++inserted;
		}
	}

	while (inserted < pend.size())
	{
		typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), pend[inserted]);
		main.insert(pos, pend[inserted]);
		++inserted;
	}
}

#endif
