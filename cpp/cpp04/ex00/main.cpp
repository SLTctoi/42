#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
    std::cout << "Create Animal polymorphism :" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "Test getType :" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << std::endl;

    std::cout << "Test makeSound polymorphism :" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    std::cout << "Delete polymorphic animals :" << std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout << std::endl;

    std::cout << "Create WrongAnimal (no polymorphism) :" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    std::cout << std::endl;

    std::cout << "Test WrongAnimal makeSound (no virtual) :" << std::endl;
    wrong_meta->makeSound();
    wrong_cat->makeSound();
    std::cout << std::endl;

    std::cout << "Delete wrong animals :" << std::endl;
    delete wrong_meta;
    delete wrong_cat;
    std::cout << std::endl;

    std::cout << "Test copy constructor :" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    dog2.makeSound();
    std::cout << std::endl;

    std::cout << "Test assignment operator :" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    cat2.makeSound();
    std::cout << std::endl;

    std::cout << "Test stack allocation :" << std::endl;
    Dog dog3;
    Cat cat3;
    dog3.makeSound();
    cat3.makeSound();
    std::cout << std::endl;

    std::cout << "Destructors :" << std::endl;
    return 0;
}