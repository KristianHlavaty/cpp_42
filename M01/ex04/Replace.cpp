#include "Replace.hpp"
#include <iostream>
#include <fstream>

//The cerr object in C++ is used to print error messages to the standard error stream (cerr).
//in C++98, std::ifstream and std::ofstream constructors do not accept std::string objects directly. Instead, they require C-style strings (const char*).
//thats why I need to use c_str() method to convert std::string to const char*.

bool Replace::replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) const {
	std::ifstream infile(filename.c_str());
	if(!infile.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return false;
	}
	
	std::string outfile_name = filename + ".replace";
	std::ofstream outfile(outfile_name.c_str());
	if(!outfile.is_open())
	{
		std::cerr << "Error: could not create file " << outfile_name << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		std::string replaced_line = _replaceOccurrences(line, s1, s2);
		outfile << replaced_line << std::endl;
	}

	infile.close();
	outfile.close();

	return true;
}

std::string Replace::_replaceOccurrences(const std::string& line, const std::string& s1, const std::string& s2) const
{
    std::string result = line;
    size_t pos = 0;
    while ((pos = result.find(s1, pos)) != std::string::npos)
	{
        result.erase(pos, s1.length());
        result.insert(pos, s2);
        pos += s2.length();
    }
    return result;
}