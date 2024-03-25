#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() : currentSize(0), nextIndex(0) {}

void PhoneBook::addContact(const Contact &contact)
{
	int index = nextIndex % 8; // 8 is the size from the subject
	contacts[index] = contact;
	nextIndex++;
	if (currentSize < 8)
	{
		currentSize++;
	}
}

// std::cout: This is the standard output stream used to perform console output.
// std::setw(10): This manipulator sets the field width for the next input/output operation.
// std::cout statement uses a sequence of insertion operators (<<) to send output to the console
void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < currentSize; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << "|" << std::endl;
	}
}

void PhoneBook::displayContactDetails(int index) const
{
	if (index >= 0 && index < currentSize)
	{
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << "Invalid index" << std::endl;
	}
}

// subject:
// If the text is longer than the column,
// it must be truncated and the last displayable character must be replaced by a
// dot (’.’).

std::string PhoneBook::truncate(const std::string &str) const
{
	if (str.length() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	return str;
}