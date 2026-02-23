#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

PhoneBook::PhoneBook() : size_(0), next_(0)
{
}

bool	PhoneBook::isCommand(const std::string& input, const std::string& cmd) const
{
	std::size_t	i;
	std::size_t	j;

	i = 0;
	while (i < input.length() && std::isspace(static_cast<unsigned char>(input[i])))
		i++;
	j = 0;
	while (i + j < input.length() && j < cmd.length())
	{
		if (input[i + j] != cmd[j])
			return false;
		j++;
	}
	if (j != cmd.length())
		return false;
	i = i + j;
	while (i < input.length())
	{
		if (!std::isspace(static_cast<unsigned char>(input[i])))
			return false;
		i++;
	}
	return true;
}

int	PhoneBook::launch()
{
	std::string	input;

	while (true)
	{
		if (readLine("\033[32mPhoneBook> \033[0m", input) < 0)
			break;
		if (isCommand(input, "ADD"))
		{
			if (addContact() < 0)
				break;
		}
		else if (isCommand(input, "SEARCH"))
		{
			if (searchContact() < 0)
				break;
		}
		else if (isCommand(input, "EXIT"))
			break;
		else if (!isBlank(input))
			std::cout << "\033[31m" << "Invalid command. Available: ADD, SEARCH, EXIT" << "\033[0m" << std::endl;
	}
	if (std::cin.eof())
		std::cout << std::endl;
	cleanup();
	return 0;
}

void	PhoneBook::cleanup()
{
	for (int i = 0; i < CAP; ++i)
		contacts[i].cleanup();
	size_ = 0;
	next_ = 0;
}

int	PhoneBook::readLine(const std::string& prompt, std::string& input) const
{
	std::cout << prompt << std::flush;
	if (!std::getline(std::cin, input))
		return -1;
	if (std::cin.eof())
		return -1;
	return 0;
}

int	PhoneBook::internalIndex(int index) const
{
	if (size_ == CAP)
		return (next_ + index - 1) % CAP;
	return index - 1;
}

int	PhoneBook::min(int a, int b) const
{
	if (a < b)
		return a;
	return b;
}
