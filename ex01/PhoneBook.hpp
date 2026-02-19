#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	start();

	private:
		Contact	contacts[8];
		void	addContact();
		void	searchContact();
};

#endif
