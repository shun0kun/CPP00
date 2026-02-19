#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact();
		int					getIndex() const;
		const std::string&	getFirstName() const;
		const std::string&	getLastName() const;
		const std::string&	getNickName() const;
		const std::string&	getPhoneNumber() const;
		const std::string&	getDarkestSecret() const;
		void				setIndex(int index);
		void				setFirstName(const std::string &first_name);
		void				setLastName(const std::string &last_name);
		void				setNickName(const std::string &nick_name);
		void				setPhoneNumber(const std::string &phone_number);
		void				setDarkestSecret(const std::string &darkest_secret);

	private:
		int					index_;
		std::string			first_name_;
		std::string			last_name_;
		std::string			nick_name_;
		std::string			phone_number_;
		std::string			darkest_secret_;
};

#endif
