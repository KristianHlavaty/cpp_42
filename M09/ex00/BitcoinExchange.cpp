#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{

}
// testing ssh key
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
	std::ifstream fin(filename.c_str());
	if(!fin.is_open())
		throw std::runtime_error("Error: Could not open file.");

	std::string line, date;
	double price;

	if (std::getline(fin,line) && line == "date,exchange_rate")
	{
		// doing nothing, just skiping the header line
	}

	while(std::getline(fin, line))
	{
		std::stringstream ss(line);
		if (std::getline(ss, date, ',') && ss >> price)
		{
			database[date] = price;
		}
		else
		{
			std::cerr << "Error: MAlformed line in database: " << line << std::endl;
		}
	}
	fin.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
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

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month < 1 || month > 12)
		return false;

	// every 4 year -> leap year
	// every 100 years -> not a leap year
	// every 400 years -> leap year again
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return false;
	if(day < 1 || day > daysInMonth[month])
	{
		return false;
	}
	return true; 
}

bool BitcoinExchange::isValidValue(double value) const
{
	return value >= 0.0 && value <= 1000.0;
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
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
	if(!isValidDate(date))
		throw std::invalid_argument("Error: Invalid date format.");
	
	if(!isValidValue(value))
		throw std::invalid_argument("Error: Invalid value.");

	if(database.empty())
		throw std::runtime_error("Error: Database is empty.");

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