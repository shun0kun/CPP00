#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		int					launch();

	private:
		static const int	CAP = 8;
		int					size_;
		int					next_;
		Contact				contacts[CAP];
		void				cleanup();
		int					addContact();
		int					searchContact() const;
		bool				isCommand(const std::string& input, const std::string& cmd) const;
		bool				isBlank(const std::string& str) const;
		int					getField(const std::string& prompt, std::string& input) const;
		int					readLine(const std::string& prompt, std::string& input) const;
		int					internalIndex(int index) const;
		std::string			truncateWithDot(const std::string& str, std::size_t len) const;
		void				print_columns(int index) const;
		void				print_contact_info(int index) const;
		int					min(int a, int b) const;
};

#endif
