#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
    std::cout << "Test sujet :" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    std::cout << std::endl;

    std::cout << "Create array of Animals :" << std::endl;
    const int size = 6;
    Animal* animals[size];
    
    for (int idx = 0; idx < size / 2; idx++) {
        animals[idx] = new Dog();
    }
    for (int idx = size / 2; idx < size; idx++) {
        animals[idx] = new Cat();
    }
    std::cout << std::endl;

    std::cout << "Test makeSound :" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        animals[idx]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "Delete all animals :" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        delete animals[idx];
    }
    std::cout << std::endl;

    std::cout << "Test deep copy Dog :" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    Dog dog3;
    dog3 = dog1;
    std::cout << std::endl;

    std::cout << "Test deep copy Cat :" << std::endl;
    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;
    std::cout << std::endl;

    std::cout << "Destructors :" << std::endl;
    return 0;
}