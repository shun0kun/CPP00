#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : next_(0), size_(0)
{
}

void	PhoneBook::launch()
{
	std::string	input;

	while (true)
	{
		std::cout << "> " << std::flush;
		if (!std::getline(std::cin, input))
		{
			// EOFが来たら残ったbufferを出力しないように終了する。
		}
		if (input == "ADD")
			addContact();
		else if (input == "SERCH")
			searchContact();
		else if (input == "EXIT")
			break ;
		else
		{

		}
	}
}

void	PhoneBook::addContact()
{
	std::string	input;

	std::cout << "First name: " << std::flush;
	std::getline(std::cin, input);
	contacts[next_].setFirstName(input);

	std::cout << "Last name: " << std::flush;
	std::getline(std::cin, input);
	contacts[next_].setLastName(input);

	std::cout << "Nick name: " << std::flush;
	std::getline(std::cin, input);
	contacts[next_].setNickName(input);

	std::cout << "Phone number: " << std::flush;
	std::getline(std::cin, input);
	contacts[next_].setPhoneNumber(input);

	std::cout << "Darkest secret: " << std::flush;
	std::getline(std::cin, input);
	contacts[next_].setDarkestSecret(input);

	if (size_ == 8)
	{
		next_ = (next_ + 1) % 8;
	}
	else
	{
		next_++;
		size_++;
	}
}

void	PhoneBook::print_columns(int i, int index)
{
	std::cout << std::right;
	std::cout << "|" << std::setw(10) << index
			<< "|" << std::setw(10) << contacts[i].getFirstName()
			<< "|" << std::setw(10) << contacts[i].getLastName()
			<< "|" << std::setw(10) << contacts[i].getNickName()
			<< "|" << std::endl;
}

void	PhoneBook::searchContact()
{
	int	index;

	index = 1;
	for (int i = next_ - 1; i >= 0; --i)
	{
		print_columns(i, index++);
	}
}
