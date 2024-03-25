#include "Contact.class.hpp"

// Constructor
// this initializes the member variables of the Contact class to the specified values—in this case
// I initialize it to empty strings—for a new Contact object. This is called an initializer list.
Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret(""){}

// In C++, "this" is a pointer that refers to the current instance of the class
void Contact::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

// Returning a const reference is more efficient for types that are expensive to copy,
// like large std::string objects, because it avoids the copy operation.
// but its read-only, so we can't change the value of the object
// if need to change in future, just delete const, &, also modify in .hpp file accordingly

// when you're inside a member function and refer to a member variable
// without any naming conflict, the this-> prefix is optional
const std::string &Contact::getFirstName() const
{
	return firstName;
}

const std::string &Contact::getLastName() const
{
	return lastName;
}

const std::string &Contact::getNickname() const
{
	return nickname;
}

const std::string &Contact::getPhoneNumber() const
{
	return phoneNumber;
}

const std::string &Contact::getDarkestSecret() const
{
	return darkestSecret;
}