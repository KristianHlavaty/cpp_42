#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc <file>" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btcExchange;
		btcExchange.loadDatabase("data.csv");

		std::ifstream input(av[1]);
		if (!input.is_open())
		{
			std::cerr << "Error: Could not open file: " << av[1] << std::endl;
			return 1;
		}

		std::string line;
		while (std::getline(input, line))
		{
			std::istringstream iss(line);
			std::string date, valueStr;

			if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
			{
				date = btcExchange.trim(date);
				valueStr = btcExchange.trim(valueStr);

				if (!btcExchange.isValidDate(date))
				{
					std::cerr << "Error: Bad input => " << line << std::endl;
					continue;
				}

				std::istringstream valueStream(valueStr);
				double value;

				if (valueStream >> value && value >= 0.0 && value <= 1000.0)
				{
					try
					{
						double result = btcExchange.calculate(date, value);
						std::cout << date << " => " << value << " = " << result << std::endl;
					}
					catch (const std::exception &e)
					{
						std::cerr << e.what() << std::endl;
					}
				}
				else
				{
					std::cerr << "Error: Invalid value => " << valueStr << std::endl;
				}
			}
			else
			{
				std::cerr << "Error: Bad input => " << line << std::endl;
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
