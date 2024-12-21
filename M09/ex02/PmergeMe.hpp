#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> generateJacobsthalNumbers(size_t size);

		template <typename Container>
		void pairAndSort(Container &sequence, Container &aList, Container &bList);

		template <typename Container>
		void recursivePairSort(Container &sequence, size_t step);

		template <typename Container>
		void insertbListElements(Container &aList, Container &bList);

		

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

// b is smaller element
// a is larger element
template <typename Container>
void PmergeMe::pairAndSort(Container& sequence, Container& aList, Container& bList)
{
	for (size_t i = 0; i + 1 < sequence.size(); i += 2)
	{
		if (sequence[i] > sequence[i + 1])
		{
			// Swapping to ensure sequence[i] is "b" and sequence[i + 1] is "a"
			std::swap(sequence[i], sequence[i + 1]);
		}
		aList.push_back(sequence[i + 1]);
		bList.push_back(sequence[i]);
	}
	// unpaired element
	if (sequence.size() % 2 != 0)
		bList.push_back(sequence.back());

	// sorting the larger elements recursively
	recursivePairSort(aList, 1);
}

template <typename Container>
void PmergeMe::insertbListElements(Container& aList, Container& bList)
{
	std::vector<int> jacobsthal = generateJacobsthalNumbers(bList.size());
	size_t inserted = 0;

	for (size_t i = 0; i < jacobsthal.size() && inserted < bList.size(); ++i)
	{
		size_t count = std::min<size_t>(jacobsthal[i] - (i > 0 ? jacobsthal[i - 1] : 0), bList.size() - inserted);
		for (size_t j = 0; j < count; ++j)
		{
			typename Container::iterator pos = std::lower_bound(aList.begin(), aList.end(), bList[inserted]);
			aList.insert(pos, bList[inserted]);
			++inserted;
		}
	}

	while (inserted < bList.size())
	{
		typename Container::iterator pos = std::lower_bound(aList.begin(), aList.end(), bList[inserted]);
		aList.insert(pos, bList[inserted]);
		++inserted;
	}
}

#endif
