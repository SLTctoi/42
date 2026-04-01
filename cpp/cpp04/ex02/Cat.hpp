#ifndef CAT_HPP
# define CAT_HPP

# include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* _CatBrain;
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &other);
        ~Cat();

        void makeSound(void) const;
        Brain* getBrain(void) const;
};


#endif