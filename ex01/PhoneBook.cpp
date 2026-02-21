#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : size_(0), next_(0)
{
}

PhoneBook::~PhoneBook()
{

	next_ = 0;
	size_ = 0;
}

int	PhoneBook::launch()
{
	std::string	input;

	while (true)
	{
		if (getInput("\033[32mPhoneBook> \033[0m", input) < 0)
			break ;
		if (input == "ADD")
			addContact();
		else if (input == "SERCH")
			searchContact();
		else if (input == "EXIT")
			break ;
		else if (input.length() != 0)
			std::cout << "\033[31m" << input <<": command not found" << "\033[0m" << std::endl;
		if (std::cin.eof())
			break ;
	}
	std::cout << std::endl;
	for (int i = 0; i < CAP; ++i)
		contacts[i].cleanup();
	return 0;
}

int	PhoneBook::addContact()
{
	std::string	input;

	if (getInput("First name: ", input) < 0)
		return -1;
	contacts[next_].setFirstName(input);

	if (getInput("Last name: ", input) < 0)
		return -1;
	contacts[next_].setLastName(input);

	if (getInput("Nick name: ", input) < 0)
		return -1;
	contacts[next_].setNickName(input);

	if (getInput("Phone number: ", input) < 0)
		return -1;
	contacts[next_].setPhoneNumber(input);

	if (getInput("Darkest secret: ", input) < 0)
		return -1;
	contacts[next_].setDarkestSecret(input);

	next_ = (next_ + 1) % CAP;
	size_ = min(size_ + 1, CAP);

	return 0;
}

int	PhoneBook::internalIndex(int index)
{
	if (size_ == CAP)
		return (next_ + index - 1) % CAP;
	return index - 1;
}

std::string	cutString(const std::string& str, int len)
{
	std::string	ret;

	if (s)
	return (ret);
}

void	PhoneBook::print_columns(int index)
{
	std::cout << std::right;
	std::cout << "|" << std::setw(10) << index
			<< "|" << std::setw(10) << contacts[internalIndex(index)].getFirstName()
			<< "|" << std::setw(10) << contacts[internalIndex(index)].getLastName()
			<< "|" << std::setw(10) << contacts[internalIndex(index)].getNickName()
			<< "|" << std::endl;
}

void	PhoneBook::print_contact_info(int index)
{
	std::cout << "First name:\t" << contacts[internalIndex(index)].getFirstName() << "\n"
			<< "Last name:\t" << contacts[internalIndex(index)].getLastName() << "\n"
			<< "Nick name:\t" << contacts[internalIndex(index)].getNickName() << "\n"
			<< "Phone number:\t" << contacts[internalIndex(index)].getPhoneNumber() << "\n"
			<< "Darkest secret:\t" << contacts[internalIndex(index)].getDarkestSecret() << "\n"
			<< std::flush;
}

int	PhoneBook::searchContact()
{
	int	index;
	std::string	input;

	index = 1;
	for (int index = 1; index <= size_; ++index)
		print_columns(index);
	std::cout << "index: " << std::flush;
	if (!std::getline(std::cin, input))
		return -1;
	if (input.length() == 1 && input[0] >= '1' && input[0] <= size_ + '0')
	{
		print_contact_info(input[0] - '0');
	}
	else
		std::cout << "Doen't exist." << std::endl;
	return 0;
}

int	PhoneBook::getInput(const std::string& prompt, std::string& input)
{
	std::cout << prompt << std::flush;
	if (!std::getline(std::cin, input))
		return -1;
	return 0;
}

int	PhoneBook::min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
