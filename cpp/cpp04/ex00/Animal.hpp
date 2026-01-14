#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
    protected:  
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal(const std::string Type);
        Animal &operator=(const Animal &other);
        ~Animal();

        virtual void makeSound(void) const;
        std::string getType(void) const;
};


#endif