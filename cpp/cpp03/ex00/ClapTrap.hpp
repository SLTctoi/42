#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

// forme canonique
class ClapTrap {
    private:  
        std::string _Name;
        int _Hp;
        int _Ep;
        int _Ad;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif