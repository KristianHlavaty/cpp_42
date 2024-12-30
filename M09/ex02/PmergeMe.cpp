#include "PmergeMe.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe()
{

}
PmergeMe::~PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_hasLeftover		= other._hasLeftover;
		_leftoverValue    	= other._leftoverValue;
		_pairCount       	= other._pairCount;
		
		_pairsVector 	  	= other._pairsVector;
		_sortedListVector  	= other._sortedListVector;

		_pairsDeque        	= other._pairsDeque;
		_sortedListDeque   	= other._sortedListDeque;
	}
	return *this;
}

// constructing pairs and doing Ford-Johnson
// reading av into buff
// spliting buff into pairs
// sorts pairs internally then sorts by the second(larger) element
// do the makeSortedList to finalize sorted order
void PmergeMe::mergeInsertVector(int ac, char **av)
{
	_pairsVector.clear();
	_sortedListVector.clear();

	std::vector<int> buff;
	_pairCount = ac - 1; 

	for (int i=1; i<ac; i++)
	{
		if (!isNumber(av[i]))
			throw std::runtime_error("Invalid input");
		int val = std::atoi(av[i]);
		buff.push_back(val);
	}

	printContainer(buff, "Before: ");

	// leftover
	_hasLeftover = false;
	_leftoverValue    = 0;
	if (_pairCount % 2 != 0)
	{
		_hasLeftover = true;
		_leftoverValue = buff[_pairCount - 1];
		_pairCount--;
	}
	splitIntoPairs(_pairsVector, buff, _pairCount);
	sortEachPair(_pairsVector);
	insertionSortBySecond(_pairsVector, _pairsVector.size() - 1);
	makeSortedList(_pairsVector, _sortedListVector, _hasLeftover, _leftoverValue);
}

// constructing pairs and doing Ford-Johnson
void PmergeMe::mergeInsertDeque(int ac, char **av)
{
	_pairsDeque.clear();
	_sortedListDeque.clear();

	std::deque<int>  buff;
	_pairCount = ac - 1; 

	for (int i=1; i<ac; i++)
	{
		if (!isNumber(av[i]))
			throw std::runtime_error("Invalid input");
		int val = std::atoi(av[i]);
		buff.push_back(val);
	}

	// leftover
	_hasLeftover = false;
	_leftoverValue    = 0;
	if (_pairCount % 2 != 0)
	{
		_hasLeftover = true;
		_leftoverValue = buff[_pairCount - 1];
		_pairCount--;
	}
	splitIntoPairs(_pairsDeque, buff, _pairCount);
	sortEachPair(_pairsDeque);
	insertionSortBySecond(_pairsDeque, _pairsDeque.size() - 1);
	makeSortedList(_pairsDeque, _sortedListDeque, _hasLeftover, _leftoverValue);
}

const std::vector<int>&PmergeMe::getSortedVector() const
{
	return _sortedListVector;
}

const std::deque<int>&PmergeMe::getSortedDeque() const
{
	return _sortedListDeque;
}

bool PmergeMe::isNumber(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-' && i == 0)
			throw std::runtime_error("Error");
		if (str[i] > '9' || str[i] < '0')
			return false;
	}
	return true;
}
