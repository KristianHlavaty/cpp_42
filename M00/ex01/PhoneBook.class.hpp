#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.class.hpp"
#include <iostream> // std::cout , std::endl
#include <iomanip> // std::setw , std::setfill
#include <string> // length(), substr()

// size 8 is given in the subject, so i use it as a constant

// In C++, strings managed by the std::string class do not require a null terminator (\0)
// to indicate the end of the string. This is a key difference from C-style strings, which
// are arrays of characters ending with a null terminator to mark the string's end.
class PhoneBook {
private:
	Contact contacts[8];
	int currentSize;
	int nextIndex;

public:
	PhoneBook();
	void addContact(const Contact &contact);
	void displayContacts() const;
	void displayContactDetails(int index) const;
	std::string truncate(const std::string &str) const;
};
#endif