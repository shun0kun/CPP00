#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>

int	PhoneBook::addContact()
{
	std::string	input;

	if (getField("First Name: ", input) < 0)
		return -1;
	contacts[next_].setFirstName(input);
	if (getField("Last Name: ", input) < 0)
		return -1;
	contacts[next_].setLastName(input);
	if (getField("Nick Name: ", input) < 0)
		return -1;
	contacts[next_].setNickName(input);
	if (getField("Phone Number: ", input) < 0)
		return -1;
	contacts[next_].setPhoneNumber(input);
	if (getField("Darkest Secret: ", input) < 0)
		return -1;
	contacts[next_].setDarkestSecret(input);
	next_ = (next_ + 1) % CAP;
	size_ = min(size_ + 1, CAP);
	return 0;
}

int	PhoneBook::getField(const std::string& prompt, std::string& input) const
{
	while (true)
	{
		if (readLine(prompt, input) < 0)
			return -1;
		if (isBlank(input))
			std::cout << "\033[31m" << "Input cannot be empty." << "\033[0m" << std::endl;
		else
			break;
	}
	return 0;
}


bool	PhoneBook::isBlank(const std::string& str) const
{
	if (str.empty())
		return true;
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}
