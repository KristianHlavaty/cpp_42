#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	complainFunctions[0] = &Harl::debug;
	complainFunctions[1] = &Harl::info;
	complainFunctions[2] = &Harl::warning;
	complainFunctions[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; ++i)
	{
        if (levels[i] == level)
		{
            (this->*complainFunctions[i])();
            return;
        }
    }
    std::cout << "Invalid level of complaint." << std::endl;
}