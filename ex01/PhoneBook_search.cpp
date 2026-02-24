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
	std::cout << "+----------+----------+----------+----------+\n"
			<< "|" << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "First Name"
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nick Name"
			<< "|\n"
			<< "+----------+----------+----------+----------+\n";
	for (int index = 1; index <= size_; ++index)
		print_columns(index);
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::ostringstream	oss;
	oss << "Enter index (1-" << size_ << "): ";
	std::string	prompt = oss.str();
	if (readLine(prompt, input) < 0)
		return -1;
	if (input.length() == 1 && input[0] >= '1' && input[0] <= size_ + '0')
		print_contact_info(input[0] - '0');
	else
		std::cout << "\033[31m" << "Invalid index." << "\033[0m" << std::endl;
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

int	PhoneBook::infoLenMax(int index) const
{
	int	max_len;
	int	arr[5];

	arr[0] = contacts[internalIndex(index)].getFirstName().length();
	arr[1] = contacts[internalIndex(index)].getLastName().length();
	arr[2] = contacts[internalIndex(index)].getNickName().length();
	arr[3] = contacts[internalIndex(index)].getPhoneNumber().length();
	arr[4] = contacts[internalIndex(index)].getDarkestSecret().length();
	max_len = arr[0];
	for (int i = 1; i < 5; ++i)
	{
		if (arr[i] > max_len)
			max_len = arr[i];
	}
	return max_len;
}

void	PhoneBook::print_contact_info(int index) const
{
	int	width = infoLenMax(index);

	std::cout << std::left;
	std::cout << '+' << std::string(width + 18, '-') << "+\n";
	std::cout << "| Contact #" << index << std::setw(width + 9) << std::right << "|\n";
	std::cout << std::left;
	std::cout << '+' << std::string(width + 18, '-') << "+\n";
	std::cout << "| First Name:     " << std::setw(width) << contacts[internalIndex(index)].getFirstName() << " |\n"
			<< "| Last Name:      " << std::setw(width) << contacts[internalIndex(index)].getLastName() << " |\n"
			<< "| Nick Name:      " << std::setw(width) << contacts[internalIndex(index)].getNickName() << " |\n"
			<< "| Phone Number:   " << std::setw(width) << contacts[internalIndex(index)].getPhoneNumber() << " |\n"
			<< "| Darkest Secret: " << std::setw(width) << contacts[internalIndex(index)].getDarkestSecret() << " |\n";
	std::cout << '+' << std::string(width + 18, '-') << '+' << std::endl;
	std::cout << std::right;
}
