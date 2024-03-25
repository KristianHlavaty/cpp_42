#include "PhoneBook.class.hpp"
#include <iostream> // std::cout , std::cin , std::endl, std::getline, clear, ignore
#include <limits> // std::numeric_limits, std::streamsize, max

// std::cin used to read data from the standard input
// create new Contact object and set its member variables
// add the new Contact object to the PhoneBook
void addNewContact(PhoneBook &phoneBook)
{
	Contact contact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);

	phoneBook.addContact(contact);
}

// (std::cin >> variable) attempts to read input from the
// standard input and store it in variable.

// If the input is of a different type (text)
// std::cin enters an error state, and the input operation fails.
// The erroneous input remains in the input buffer
// that is why I need to clear the error state and ignore the input

// std::numeric_limits<std::streamsize>::max() 
// returns the maximum value of the streamsize type
// which is the maximum number of characters that can be stored in a stream buffer.
// basically ignore all characters until the delimiter is encountered

void searchContact(const PhoneBook &phoneBook)
{
	phoneBook.displayContacts();
	std::cout << "Enter the index of the contact you want to view: ";
	int index = 0;
	if (!(std::cin >> index))
	{
		std::cin.clear(); // Clear the error flags
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input
		std::cout << "Invalid input." << std::endl;
		return;
	}
	// handle the next line character
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	phoneBook.displayContactDetails(index);
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "EXIT")
		{
			break;
		} 
		else if (command == "ADD")
		{
			addNewContact(phoneBook);
		} 
		else if (command == "SEARCH")
		{
			searchContact(phoneBook);
		}
		else
		{
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	return 0;
}