#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> database;

		bool isValidDate(const std::string &date) const;
		bool isValidValue(double value) const;
		std::string findClosestDate(const std::string &data) const;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void loadDatabase(const std::string &filename);
		double calculate(const std::string &date, double value) const;
};
#endif