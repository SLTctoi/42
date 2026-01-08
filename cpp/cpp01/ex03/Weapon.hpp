#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
    private:
        std::string _Type;

    public:
        Weapon();
        ~Weapon();
        
        std::string getType() const;
        std::string setType(const std::string type);
};

#endif