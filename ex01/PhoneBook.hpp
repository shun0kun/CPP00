#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		// ~PhoneBook();
		void	launch();

	private:
		Contact	contacts[8];
		int		next_;
		int		size_;
		void	addContact();
		void	searchContact();
		void	print_columns(int i, int index);
};

#endif
