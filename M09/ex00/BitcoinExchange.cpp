#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		database = other.database;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream fileinput(filename.c_str());
	if(!fileinput.is_open())
		throw std::runtime_error("Error: Could not open file.");

	skipHeaderLine(fileinput);

	std::string line;

	while(std::getline(fileinput, line))
	{
		std::string date;
		double price;

		if (parseDatabaseLine(line, date, price))
		{
			database[date] = price;
		}
		else
		{
			std::cerr << "Error: MAlformed line in database: " << line << std::endl;
		}
	}
}

bool BitcoinExchange::parseDatabaseLine(const std::string &line, std::string &date, double &price) const
{
	std::stringstream ss(line);
	if(std::getline(ss, date, ',') && ss >> price)
		return true;
	return false;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	// format should be like this YYYY-MM-DD
	if(date.length() != 10)
		return false;
	
	for(size_t i = 0; i < date.length(); ++i)
	{
		if((i == 4 || i == 7) && date[i] != '-')
			return false;
		else if ((i != 4 && i != 7) && !std::isdigit(date[i]))
		{
			return false;
		}
	}

	int year, month, day;
	parseDate(date, year, month, day);

	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month < 1 || month > 12)
		return false;

	int maxDays = daysInMonth[month];
	if (month == 2 && isLeapYear(year))
		maxDays = 29;

	return day >= 1 && day <= maxDays; 
}

void BitcoinExchange::parseDate(const std::string &date, int &year, int &month, int &day) const
{
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
}

bool BitcoinExchange::isValidValue(double value) const
{
	if(value < 0.0)
		return false;
	else if (value > 1000.0)
		return false;
	else
		return true;
}

bool BitcoinExchange::isValidInput(const std::string &date, double value) const
{
	if(!isValidDate(date))
	{
		std::cerr << "Error: Invalid date format." << std::endl;
		return false;
	}
		
	if(!isValidValue(value))
	{
		std::cerr << "Error: Invalid value." << std::endl;
		return false;
	}

	if(database.empty())
	{
		std::cerr << "Error: Database is empty." << std::endl;
		return false;
	}

	return true;
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
	// from subject: Be careful to use the
	// lower date and not the upper one.
	
	// lower_bound returns an iterator pointing to the first element
	// in the map whose key is not less than the given date
	std::map<std::string, double>::const_iterator it = database.lower_bound(date);

	if (it == database.end() || it->first > date)
	{
		if(it == database.begin())
			throw std::runtime_error("Error: No earlier date found in database");
		--it;
	}
	return it->first;
}

double BitcoinExchange::calculate(const std::string &date, double value) const
{
	if(!isValidInput(date, value))
		throw std::invalid_argument("Error: Invalid input.");
	
	std::string closestDate = findClosestDate(date);

	std::map<std::string, double>::const_iterator it = database.find(closestDate);
	if(it == database.end())
		throw std::runtime_error("Error: Date not found in database.");

	return value * it->second;
}

std::string BitcoinExchange::trim(const std::string &str) const
{
	size_t start = 0;
	while(start < str.length() && std::isspace(str[start]))
		++start;
	
	size_t end = str.length();
	while (end > start && std::isspace(str[end - 1]))
		--end;

	return str.substr(start, end - start);
}

void BitcoinExchange::skipHeaderLine(std::ifstream &fileinput) const
{
	std::string header;
	if(std::getline(fileinput, header) && header == "date,exchange_rate")
	{
		// doing nothing, just skiping the header line
	}
}

bool BitcoinExchange::isLeapYear(int year) const
{
	// every 4 year -> leap year
	// every 100 years -> not a leap year
	// every 400 years -> leap year again
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
