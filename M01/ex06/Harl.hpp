#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();

		void (Harl::*complainFunctions[4])();
		std::string levels[4];
	public:
		Harl();
		void complain(std::string level);
		void filter(std::string level);
};

#endif