#include "PhoneBook.hpp"
#include <iostream>

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
