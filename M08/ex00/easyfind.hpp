#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

// need typename T::value_type, T* would work only for raw arrays
template<typename T>
typename T::value_type* easyFind(T &containerOfIntegers, int integer)
{
	if(containerOfIntegers.empty())
	{
		throw std::runtime_error("Container is empty"); // so it doesnt segfaults with empty vector
	}
	for(typename T::iterator it = containerOfIntegers.begin(); it != containerOfIntegers.end(); ++it)
	{
		if(*it == integer)
		{
			return &(*it);
		}
	}
	// if didnt find
	throw std::runtime_error("Value not found in container");
}
#endif