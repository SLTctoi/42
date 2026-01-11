#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
    private:
        std::string _Name;
        Weapon *_Weapon;

    public:
        HumanB(const std::string &name);
        ~HumanB();

        void setWeapon(Weapon &weapon);
        void attack() const;
};

// * sinon peut pas etre null ?
#endif