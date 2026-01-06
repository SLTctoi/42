#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>

class PhoneBook {
    private:
        Contact contacts[8];
        
    public:
        void add();
        void search();
};

#endif