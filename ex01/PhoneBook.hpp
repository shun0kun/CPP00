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
		bool				isCommand(const std::string& input, const std::string& cmd) const;

		int					readLine(const std::string& prompt, std::string& input) const;
		int					internalIndex(int index) const;
		int					min(int a, int b) const;
		
		int					addContact();
		int					getField(const std::string& prompt, std::string& input) const;
		bool				isBlank(const std::string& str) const;

		int					searchContact() const;
		std::string			truncateWithDot(const std::string& str, std::size_t len) const;
		void				print_columns(int index) const;
		int					infoLenMax(int index) const;
		void				print_contact_info(int index) const;
};

#endif
