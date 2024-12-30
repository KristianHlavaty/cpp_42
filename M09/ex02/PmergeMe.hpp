#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <cmath>
#include <ctime>

// Ford Johnson(Merge-Insertion) algo
// 1) split the input into pairs
// 2) sort each pair so the smaller element is first
// 3) sort the pairs by their larger element (the second element)
// 4) create a master list of the larger elements
// 5) insert the smaller elements into this master list using a Jacobsthal-based sequence
// 6) if there's an _leftoverValue leftover element, insert it last

class PmergeMe
{
	private:
		template <typename Container>
		void sortEachPair(Container &pairsCont);

		template <typename Container>
		void binaryInsert(Container &sortedListCont, int value, int index);

		template <typename Container>
		void insertionSortBySecond(Container &pairsCont, int endIndex);

		template <typename ContainerOfPairs, typename ContainerOfInts>
		void splitIntoPairs(ContainerOfPairs &pairsCont, ContainerOfInts &buff, int _pairCount);

		template<typename PairsContainer, typename IntContainer>
		void makeSortedList(PairsContainer &pairsCont, IntContainer &sortedList, bool _hasLeftover, int _leftoverValue);

		std::vector< std::pair<int,int> > _pairsVector;
		std::vector<int> _sortedListVector;

		std::deque< std::pair<int,int> > _pairsDeque;
		std::deque<int> _sortedListDeque;

		bool _hasLeftover;
		int _leftoverValue;
		int _pairCount;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		
		void mergeInsertVector(int ac, char **av);
		void mergeInsertDeque(int ac, char **av);
		const std::vector<int> &getSortedVector() const;
		const std::deque<int> &getSortedDeque()  const;

		bool isNumber(const char *str);
};

// for each (small, large) pair, ensuring the smaller is first and larger is second
template <typename Container>
void PmergeMe::sortEachPair(Container &pairsCont)
{
	for (typename Container::iterator it = pairsCont.begin();
		it != pairsCont.end(); ++it)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

// inserting value into the sortedContainer
template <typename Container>
void PmergeMe::binaryInsert(Container &sortedListCont, int value, int index)
{
	if (index > static_cast<int>(sortedListCont.size()))
		index = sortedListCont.size();

	typename Container::iterator it
		= std::lower_bound(sortedListCont.begin(), sortedListCont.begin() + index, value);

	if (it == sortedListCont.end())
		sortedListCont.push_back(value);
	else
		sortedListCont.insert(it, value);
}

// do insertion sort on the array of pairs
// by comparing their second element (the larger)
template <typename Container>
void PmergeMe::insertionSortBySecond(Container &pairsCont, int endIndex)
{
	if (endIndex < 1)
		return;

	// sorting subrange up to endIndex-1
	insertionSortBySecond(pairsCont, endIndex - 1);

	// now inserting pairsCont[endIndex] into the sorted subrange [0..endIndex-1]
	typename Container::value_type keyPair = pairsCont[endIndex];

	int j = endIndex - 1;
	// shifting bigger elements up
	while (j >= 0 && pairsCont[j].second > keyPair.second)
	{
		pairsCont[j + 1] = pairsCont[j];
		j--;
	}
	pairsCont[j + 1] = keyPair;
}

// dividing the list of numbers into (small, large) pairs
// and pushing them into the pairsCont
template <typename ContainerOfPairs, typename ContainerOfInts>
void PmergeMe::splitIntoPairs(ContainerOfPairs &pairsCont, ContainerOfInts &buff, int _pairCount)
{
	for (int i = 0; i < _pairCount; i += 2)
	{
		typename ContainerOfPairs::value_type newPair;
		newPair.first = buff[i];
		newPair.second = buff[i + 1];
		pairsCont.push_back(newPair);
	}
	buff.clear();
}

// making an initial "sorted container" from the largest elements
// keeping the smaller elements in a "pending" container
// using Jacobsthal-based insertion to place the smaller elements back
template<typename PairsContainer, typename IntContainer>
void PmergeMe::makeSortedList(PairsContainer &pairsCont, IntContainer &sortedList, bool _hasLeftover, int _leftoverValue)
{
	// for smaller elements
	IntContainer pend;
	// moving all larger elements (second) to finalContainer
    // and storing smaller elements (first) in pendingSmalls
	for (size_t i = 0; i < pairsCont.size(); i++)
	{
		// pairsCont[i].second => a_i
		sortedList.push_back(pairsCont[i].second); 
		// pairsCont[i].first => b_i
		pend.push_back(pairsCont[i].first);       
	}

	// inserting b1 (first small) at the front of sortedList
	if (!pend.empty())
		sortedList.insert(sortedList.begin(), pend[0]);

	// using a Jacobsthal-based sequence to insert the rest
	size_t i = 0;
	size_t jacobs_index = 1;
	while (true)
	{
		int distanceForward = (std::pow(2, jacobs_index + 1) + std::pow(-1, jacobs_index)) / 3;
		if (i + distanceForward >= pend.size())
		{
			break;
		}
		size_t start = i;
		i += distanceForward;

		//  inserting from the back of the newly advanced range
		while (i > start)
		{
			// inserting pend[i] into sortedList using the index of the larger pair's second
			// as a guiding "limit" for binary searching
			binaryInsert(sortedList, pend[i], pairsCont[i].second);
			--i;
		}
		i += distanceForward;
		++jacobs_index;
	}

	// inserting any remaining smaller elements from the end
	size_t start = i;
	i = pend.size() - 1;
	while (i > start)
	{
		binaryInsert(sortedList, pend[i], pairsCont[i].second);
		--i;
	}

	// if there was a leftover element inserting it last
	if (_hasLeftover)
	{
		binaryInsert(sortedList, _leftoverValue, static_cast<int>(sortedList.size()));
	}
}

template<typename Container>
void printContainer(const Container &vec, const std::string message)
{
	std::cout << message;
	for (typename Container::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif