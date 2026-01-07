#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
    private:
        std::string _Name;

    public:
        Zombie();
        Zombie(const std::string& name);
        ~Zombie();
        void announce( void );
        void setName(const std::string& name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
