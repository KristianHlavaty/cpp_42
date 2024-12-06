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
	std::ifstream fin(filename.c_str());
	if(!fin.is_open())
		throw std::runtime_error("Error: Could not open file.");

	std::string line, date;
	double price;
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
	// todo validation
	(void)date;
	return true; 
}

bool BitcoinExchange::isValidValue(double value) const
{
	return value >= 0.0 && value <= 150000.0;
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
	// todo find closest date in map
	return date;
}

double BitcoinExchange::calculate(const std::string &date, double value) const
{
	if(!isValidDate(date))
		throw std::invalid_argument("Error: Invalid date format.");
	
	if(!isValidValue(value))
		throw std::invalid_argument("Error: Invalid value.");

	if(database.empty())
		throw std::runtime_error("Error: Database is empty.");

	std::map<std::string, double>::const_iterator it = database.find(date);
	if(it == database.end())
		throw std::runtime_error("Error: Date not found in database.");

	return value * it->second;
}