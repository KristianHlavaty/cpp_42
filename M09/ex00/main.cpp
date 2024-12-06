#include <iostream>
#include <map>
#include <fstream> //check if i can actually use it in cpp98
#include <sstream>
#include <vector>

int main()
{
	std::cout << "reading csv file" << std::endl;
	
	std::fstream fin;

	fin.open("data.csv", std::ios::in);

	if(!fin.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
	}

	std::vector<std::string> row;
	std::string line, word;
	while(getline(fin, line))
	{
		row.clear();
		std::stringstream ss(line);
		while(getline(ss, word, ','))
		{
			row.push_back(word);
		}
		for(size_t j = 0; j < row.size(); j++)
		{
			std::cout << "Field" << j + 1 << row[j] << std::endl;
		}
	}
	fin.close();
	return 0;
}