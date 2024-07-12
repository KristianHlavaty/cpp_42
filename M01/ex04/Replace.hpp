#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class Replace {
	private:
    	std::string _replaceOccurrences(const std::string& line, const std::string& s1, const std::string& s2) const;
	public:
		bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) const;
};

#endif