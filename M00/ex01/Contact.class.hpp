#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string> // std::string

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

// passing by reference to avoid copying
// const, cuz there is no reason to change the value of the parameter
public:
	Contact();
	void setFirstName(const std::string &firstName); 
	void setLastName(const std::string &lastName);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	const std::string &getPhoneNumber() const;
	const std::string &getDarkestSecret() const;
};

#endif