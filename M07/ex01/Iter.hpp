#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *arr, int len, void(*f)(T const &))
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