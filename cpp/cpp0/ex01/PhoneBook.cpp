#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : _contactCount(0), _nextIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_truncate(const std::string& str, size_t width) const {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}

std::string PhoneBook::_formatColumn(const std::string& str) const {
	std::string truncated = _truncate(str, 10);
	std::stringstream ss;
	ss << std::setw(10) << truncated;
	return ss.str();
}

void PhoneBook::_displayContactList() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _contactCount; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << _formatColumn(_contacts[i].getFirstName()) << "|";
		std::cout << _formatColumn(_contacts[i].getLastName()) << "|";
		std::cout << _formatColumn(_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::_displayContact(int index) const {
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::addContact() {
	std::string input;
	Contact newContact;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "First name cannot be empty!" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Last name cannot be empty!" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Nickname cannot be empty!" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Phone number cannot be empty!" << std::endl;
		return;
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Darkest secret cannot be empty!" << std::endl;
		return;
	}
	newContact.setDarkestSecret(input);

	_contacts[_nextIndex] = newContact;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_contactCount < 8)
		_contactCount++;

	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() {
	if (_contactCount == 0) {
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}

	_displayContactList();

	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	std::getline(std::cin, input);

	std::stringstream ss(input);
	int index;
	ss >> index;

	if (ss.fail() || !ss.eof() || index < 0 || index >= _contactCount) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	_displayContact(index);
}
