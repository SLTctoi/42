#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>

class HumanB {
    private:
        std::string _Name;
        Weapon::Weapon _Weapon;

    public:
        HumanB(std::string name);
        ~HumanB();
        
        void attack();
        std::string const getName();
        std::string const getWeapon();
        std::string setWeapon(std::string);
};

#endif