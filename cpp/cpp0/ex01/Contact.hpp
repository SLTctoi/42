#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string Number;
        std::string DarkestSecret;

    public:
        Contact();
        ~Contact();
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getNumber() const;
        std::string getDarkestSecret() const;
        void        setFirstName(std::string FirstName);
        void        setLastName(std::string LastName);
        void        setNickame(std::string Nickname);
        void        setNumber(std::string Number);
        void        setDarkestSecret(std::string DarkestSecret);
}

#endif 