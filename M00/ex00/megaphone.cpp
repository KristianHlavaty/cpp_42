#include <iostream>
#include <cctype>

// There is no longer Norminette, so no school headers, for is no longer forbidden etc. :]

// static_cast provides compile-time type checking, making it safer than C-style casts
// thats why i use static_cast<char> instead of (char)
// std::toupper takes int and returns int, so i use static_cast<char> to convert int to char

// for performance issues i could use /n instead of std::endl, but this is new so i
// wanted to use it just because of that

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
			}
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}

	return 0;
}