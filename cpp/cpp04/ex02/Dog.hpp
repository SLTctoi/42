#ifndef DOG_HPP
# define DOG_HPP

# include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* _DogBrain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &other);
        ~Dog();

        void makeSound(void) const;
};


#endif