#include "Contact.hpp"

const std::string&	Contact::getFirstName() const
{
	return first_name_;
}

const std::string&	Contact::getLastName() const
{
	return last_name_;
}

const std::string&	Contact::getNickName() const
{
	return nick_name_;
}

const std::string&	Contact::getPhoneNumber() const
{
	return phone_number_;
}

const std::string&	Contact::getDarkestSecret() const
{
	return darkest_secret_;
}

Contact::Contact()
{
}

void	Contact::setFirstName(const std::string &first_name)
{
	first_name_ = first_name;
}

void	Contact::setLastName(const std::string &last_name)
{
	last_name_ = last_name;
}

void	Contact::setNickName(const std::string &nick_name)
{
	nick_name_ = nick_name;
}

void	Contact::setPhoneNumber(const std::string &phone_number)
{
	phone_number_ = phone_number;
}

void	Contact::setDarkestSecret(const std::string &darkest_secret)
{
	darkest_secret_ = darkest_secret;
}

void	Contact::cleanup()
{
	first_name_.clear();
	last_name_.clear();
	nick_name_.clear();
	phone_number_.clear();
	darkest_secret_.clear();
}
