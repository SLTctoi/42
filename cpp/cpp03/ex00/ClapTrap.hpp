#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class Fixed {
    private:  
        std::string _Name;
        int _Hp;
        int _Ep;
        int _Ad;

    public:
        ClapTrap(std::string _Name);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif