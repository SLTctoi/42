#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
    protected:  
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &other);
        ~Animal();

        void makeSound(void) ;
        std::string getType(void) const;
};


#endif