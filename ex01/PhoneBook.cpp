#include "PhoneBook.hpp"
#include <string>
#include <iostream>

void	PhoneBook::addContact()
{
	std::string	input;

	std::cout << "First name: " << std::flush;
	std::getline(std::cin, input);
	contacts[0].setFirstName(input);
}

void	PhoneBook::searchContact()
{

}


void	PhoneBook::start()
{
	std::string	input;

	while (true)
	{
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
