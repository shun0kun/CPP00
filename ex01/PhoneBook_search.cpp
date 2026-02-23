#include "PhoneBook.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

int	PhoneBook::searchContact() const
{
	std::string	input;

	if (size_ == 0)
	{
		std::cout << "No contacts." << std::endl;
		return 0;
	}
	std::cout << "|" << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "First Name"
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nick Name"
			<< "|" << std::endl;
	for (int index = 1; index <= size_; ++index)
		print_columns(index);
	std::ostringstream	oss;
	oss << "Enter index (1-" << size_ << "): ";
	std::string	prompt = oss.str();
	if (readLine(prompt, input) < 0)
		return -1;
	if (input.length() == 1 && input[0] >= '1' && input[0] <= size_ + '0')
	{
		print_contact_info(input[0] - '0');
	}
	else
		std::cout << "Invalid index." << std::endl;
	return 0;
}


std::string	PhoneBook::truncateWithDot(const std::string& str, std::size_t len) const
{
	if (len == 0)
		return "";
	if (str.length() <= len)
		return (str);
	std::string	ret(str, 0, len);
	ret[len - 1] = '.';
	return (ret);
}

void	PhoneBook::print_columns(int index) const
{
	std::cout << std::right;
	std::cout << "|" << std::setw(10) << index
			<< "|" << std::setw(10) << truncateWithDot(contacts[internalIndex(index)].getFirstName(), 10)
			<< "|" << std::setw(10) << truncateWithDot(contacts[internalIndex(index)].getLastName(), 10)
			<< "|" << std::setw(10) << truncateWithDot(contacts[internalIndex(index)].getNickName(), 10)
			<< "|" << std::endl;
}

void	PhoneBook::print_contact_info(int index) const
{
	std::cout << "First name:\t" << contacts[internalIndex(index)].getFirstName() << "\n"
			<< "Last name:\t" << contacts[internalIndex(index)].getLastName() << "\n"
			<< "Nick name:\t" << contacts[internalIndex(index)].getNickName() << "\n"
			<< "Phone number:\t" << contacts[internalIndex(index)].getPhoneNumber() << "\n"
			<< "Darkest secret:\t" << contacts[internalIndex(index)].getDarkestSecret() << "\n"
			<< std::flush;
}
