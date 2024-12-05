#include <iostream>
#include <map>
#include <fstream> //check if i can actually use it in cpp98

int main()
{
	std::cout << "test" << std::endl;
	
	std::fstream fin;

	fin.open("data.csv", std::ios::in);

}