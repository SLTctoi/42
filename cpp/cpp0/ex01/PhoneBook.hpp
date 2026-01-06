#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook {
private:
	Contact	_contacts[8];
	int		_contactCount;
	int		_nextIndex;

	std::string	_truncate(const std::string& str, size_t width) const;
	std::string	_formatColumn(const std::string& str) const;
	void		_displayContactList() const;
	void		_displayContact(int index) const;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact();
};

#endif
