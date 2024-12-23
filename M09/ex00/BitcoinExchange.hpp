#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double> database;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		std::string trim(const std::string &str) const;
		bool isValidInput(const std::string &date, double value) const;
		bool isValidDate(const std::string &date) const;
		bool isValidValue(double value) const;
		std::string findClosestDate(const std::string &data) const;
		void loadDatabase(const std::string &filename);
		double calculate(const std::string &date, double value) const;
		void skipHeaderLine(std::ifstream &fin) const;
		bool isLeapYear(int year) const;
		void parseDate(const std::string &date, int &year, int &month, int &day) const;
		bool parseDatabaseLine(const std::string &line, std::string &date, double &price) const;

};
#endif