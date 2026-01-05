# include <Contact.hpp>

std::string Contact::getFirstName() const {
    return (FirstName);
}

std::string Contact::getLastName() const {
    return (LastName);
}

std::string Contact::getNickname() const {
    return (Nickname);
}

std::string Contact::getNumber() const {
    return (getNumber);
}

std::string Contact::getDarkestSecret() const {
    return (getDarkestSecret);
}

void    Contact::setFirstName(std::string s) {
    FirstName = s;
}

void    Contact::setLastName(std::string s) {
    LastName = s;
}

void    Contact::setNickame(std::string s) {
    Nickname = s;
}

void    Contact::setNumber(std::string s) {
    Number = s;
}

void Contact::setDarkestSecret(std::string s) {
    DarkestSecret = s;
}