#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int					launch();

	private:
		static const int	CAP = 8;
		int					size_;
		int					next_;
		Contact				contacts[CAP];
		int					addContact();
		int					searchContact();
		int					getInput(const std::string& prompt, std::string& input);
		int					internalIndex(int index);
		void				print_columns(int index);
		void				print_contact_info(int index);
		int					min(int a, int b);
};

#endif
