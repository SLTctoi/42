#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>

class HumanA {
    private:
        std::string _Name;
        Weapon::Weapon _Weapon;

    public:
        HumanA(std::string name, std::string weapon);
        ~HumanA();
        
        void attack();
        std::string getName() const;
        std::string getWeapon() const;
};
#endif