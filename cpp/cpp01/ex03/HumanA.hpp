#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {
    private:
        std::string _Name;
        Weapon &_Weapon;

    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();

        void attack() const;
};

// & pour renvoyer direct a l'objet weapon ?
#endif