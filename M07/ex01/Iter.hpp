#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

// need the second typename for
// " The third parameter can be an instantiated function template"
// T - type of the elements in arr
// F - type of the callable object (that will be applied to each element in arr)
template <typename T, typename F>
void iter(T *arr, int len, F f)
{
	if (len < 0)
	{
		std::cout << "no negative len pls";
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		f(arr[i]);
	}
}

#endif